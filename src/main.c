/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:17:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/09/10 17:39:49 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl_md5.h"

void    write_specified(int output, char* content)
{
    write(output, content, ft_strlen(content));
}

char* init_msg(char* msg, t_var *data)
{
    char* new_msg;
    size_t new_len;
    size_t len;

    len = (unsigned long int)ft_strlen(msg);
    data->len = len * 8;
    new_len = 512 * (((data->len + 1) / 512) + 1);
    if (!(new_msg = (char*)malloc(sizeof(char) * new_len)))
        return (0);
    ft_bzero(new_msg, new_len);
    ft_strcpy(new_msg, msg);
    new_msg[len] = 0x80;
    ft_memcpy(&(new_msg[(new_len / 8) - 8]), &(data->len), 8);
    return (new_msg);
}

unsigned int leftrotate (unsigned int x, unsigned int offset)
{
    return ( x << offset ) | ( x >> (32 - offset));
}

void abcd_modif(unsigned int* msg, unsigned int i, t_var *data)
{
    unsigned int tmp;

    tmp = data->d;
    data->d = data->c;
    data->c = data->b;
    data->b = leftrotate(data->a + data->f + data->k[i] + msg[data->g], data->r[i]) + data->b;
    data->a = tmp;
}

void    main_while(char *msg, t_var *data, int i)
{
    while (i < 64)
    {
        if (i < 16)
        {
            data->f = (data->b & data->c) | ((~data->b) & data->d);
            data->g = i;
        }
        else if (i < 32)
        {
            data->f = (data->d & data->b) | ((~data->d) & data->c);
            data->g = (i * 5 + 1) % 16;
        }
        else if (i < 48)
        {
            data->f = data->b ^ data->c ^ data->d;
            data->g = (i * 3 + 5) % 16;
        }
        else
        {
            data->f = data->c ^ (data->b | (~data->d));
            data->g = (i * 7) % 16;
        }
        abcd_modif((unsigned int*)msg, i, data);
        i++;
    }
}

char* byte_to_hex(uint8_t* mem, unsigned int bytes)
{
    char*           result;
    unsigned int    i;
    char*           tmp;
    char*            one;

    one = 0;
    if (!(result = (char*)malloc((sizeof(char) * bytes * 2) + 1)))
        return (0);
    i = 0;
    while (i < bytes)
    {
        tmp = ft_itoa_base((int)(mem[i]), "0123456789abcdef");

        if (ft_strlen(tmp) == 1)
        {
            one = ft_strjoin("0",tmp);
            ft_strdel(&tmp);
            tmp = one;
            one = 0;
        }
        ft_strcpy(&(result[i * 2]), tmp);
        ft_strdel(&tmp);
        i++;
    }
    return (result);
}

char*   md5(char* msg, t_var *data)
{
    unsigned int    bit;
    char*           result;
    
    bit = 0;
    while (bit < data->len)
    {
        data->a = data->h0;
        data->b = data->h1;
        data->c = data->h2;
        data->d = data->h3;
        main_while(msg + (int)(bit / 8), data, 0);
        bit += 512;
        data->h0 += data->a;
        data->h1 += data->b;
        data->h2 += data->c;
        data->h3 += data->d;
    }
    if (!(result = (char*)malloc(sizeof(int) * 4)))
        return (0);
    ft_memcpy(result, &(data->h0), 4);
    ft_memcpy(result + 4, &(data->h1), 4);
    ft_memcpy(result + 8, &(data->h2), 4);
    ft_memcpy(result + 12, &(data->h3), 4);
    ft_strdel(&msg);
    return (result);
}
void    init_var(t_var *data)
{
    unsigned int    i;
    static unsigned int tmp[16] = {7,12,17,22,5,9,14,20,4,11,16,23,6,10,15,21};
    
    ft_bzero(data, sizeof(t_var));
    data->h0 = 0x67452301;
    data->h1 = 0xEFCDAB89;
    data->h2 = 0x98BADCFE;
    data->h3 = 0x10325476;
    i = 0;
    while (i < 64)
    {
        data->k[i] = (unsigned int)(floor(fabs(sin(i + 1)) * pow(2,32)));
        i++;
    }
    i = 0;
    while (i < 64)
    {
        data->r[i] = tmp[(i % 4) + (4 * (int)(i / 16))];
        i++;
    }
}

int main(int ac, char** av)
{
    char*   msg;
    t_var* data;

    (void)ac;
    if (!(data = (t_var*)malloc(sizeof(t_var) * 1)))
        return (0);
    init_var(data);
    msg = init_msg(av[1], data);
    msg = md5(msg, data);
    ft_printf("%s",byte_to_hex((void*)msg, 16));
    return (0);
}