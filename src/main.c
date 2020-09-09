/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:17:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/09/09 12:00:00 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

void    write_specified(int output, char* content)
{
    write(output, content, ft_strlen(content));
}

char* init_msg(char* msg)
{
    char* new_msg;
    size_t new_len;
    size_t len;
    size_t lenBit;
    static int i = 0;;

    len = (unsigned long int)ft_strlen(msg);
    lenBit = len * 8;
    new_len = 512 * (((lenBit + 1) / 512) + 1);
    if (!(new_msg = (char*)malloc(sizeof(char) * new_len)))
        return (0);
    ft_bzero(new_msg, new_len);
    ft_memcpy(new_msg, &(lenBit), 8);
    ft_strcpy(&(new_msg[8]), msg);
    new_msg[len + 8] = 0x80;
    return (new_msg);
}

int leftrotate (int x, int offset)
{
    return ( x << offset ) | ( x >> (32 - offset));
}

void abcd_modif(unsigned int* msg, unsigned int i, t_data *data)
{
    unsigned int tmp;

    tmp = (*data).d;
    (*data).d = (*data).c;
    (*data).c = (*data).b;
    (*data).b = leftrotate((*data).a + (*data).f + (*data).k[i] + msg[(*data).g], (*data).r[i]) + (*data).b;
    (*data).a = tmp;
}

void    main_while(char *msg, t_data *data, int i)
{
    while (i < 64)
    {
        if (i < 16)
        {
            (*data).f = ((*data).b & (*data).c) | ((~(*data).b) & (*data).d);
            (*data).g = i;
        }
        else if (i < 32)
        {
            (*data).f = ((*data).d & (*data).b) | ((~(*data).d) & (*data).c);
            (*data).g = (i * 5 + 1) % 16;
        }
        else if (i < 48)
        {
            (*data).f = (*data).b ^ (*data).c ^ (*data).d;
            (*data).g = (i * 3 + 5) % 16;
        }
        else
        {
            (*data).f = (*data).c ^ ((*data).b | (~(*data).d));
            (*data).g = (i * 7) % 16;
        }
        abcd_modif((int*)msg, i, data);
        i++;
    }
}

char* byte_to_hex(uint8_t* mem, unsigned int bytes)
{
    char*           result;
    unsigned int    i;
    char*           tmp;

    if (!(result = (char*)malloc((sizeof(char) * bytes * 2) + 1)))
        return (0);
    i = 0;
    while (i < bytes)
    {
        tmp = ft_itoa_base((int)(mem[i]), "0123456789abcdef");
        ft_strcpy(result + (i * 2), tmp);
        ft_strdel(&tmp);
        i++;
    }
    return (result);
}

char*   md5(char* msg, t_data *data)
{
    unsigned int    bit;
    char*           result;
    
    bit = 0;
    while (bit < 512 * (((*((unsigned int*)msg)) / 512) + 1))
    {
        (*data).a = (*data).h0;
        (*data).b = (*data).h1;
        (*data).c = (*data).h2;
        (*data).d = (*data).h3;
        main_while(msg + (bit / 8), &data, 0);
        bit += 512;
        (*data).h0 += (*data).a;
        (*data).h1 += (*data).b;
        (*data).h2 += (*data).c;
        (*data).h3 += (*data).d;
    }
    if (!(result = (char*)malloc(sizeof(int) * 4)))
        return (0);
    ft_memcpy(result, &((*data).h0), 4);
    ft_memcpy(result + 4, &((*data).h1), 4);
    ft_memcpy(result + 8, &((*data).h2), 4);
    ft_memcpy(result + 12, &((*data).h3), 4);
    ft_strdel(&msg);
    return (result);
}

int main(int ac, char** av)
{
    char*   msg;
    t_data  data;

    msg = init_msg("test"/*find_msg(ac, av)*/);
    msg = md5(msg, &data);
    ft_printf("%s",byte_to_hex((void*)msg, 16));
    return (0);
}