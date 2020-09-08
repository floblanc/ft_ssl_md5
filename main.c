/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:17:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/09/08 17:01:42 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    writeSpecified(int output, char* content)
{
    write(output, content, ft_strlen(content));
}

char* initMsg(char* msg)
{
    char* newMsg;
    size_t newLen;
    size_t len;
    size_t lenBit;
    static int i = 0;;

    len = (unsigned long int)ft_strlen(msg);
    lenBit = len * 8;
    newLen = 512 * (((lenBit + 1) / 512) + 1);
    if (!(newMsg = (char*)malloc(sizeof(char) * newLen)))
        return (0);
    ft_bzero(newMsg, newLen);
    ft_memcpy(newMsg, &(lenBit), 8);
    ft_strcpy(&(newMsg[8]), msg);
    newMsg[len + 8] = 0x80;
    return (newMsg);
}

char*   md5(char* msg, int* shifts, int* consts)
{
    unsigned int bit;
    
    bit = 0;
    while (bit < 512 * (((*((unsigned int*)msg)) / 512) + 1))
    {
        main_while(msg + bit / 8, FATStruct);
        bit += 512;
    }

    return (result);
}

int main(int ac, char** av)
{

    return (0);
}