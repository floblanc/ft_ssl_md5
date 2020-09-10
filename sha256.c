/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:40:34 by judumay           #+#    #+#             */
/*   Updated: 2020/09/10 14:41:333 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

/*void    write_specified(int output, char* content)
{
	write(output, content, ft_strlen(content));
}

void abcd_modif(unsigned int* msg, unsigned int i, t_var *data)
{
	unsigned int tmp;
	tmp = data->d;
	data->d = data->c;
	data->c = data->b;
	ft_printf("rotateLeft(%u + %u + %u + %u, %u) i = %u\n", data->a, data->f, data->k[i], msg[data->g], data->r[i], i);
	data->b = leftrotate(data->a + data->f + data->k[i] + msg[data->g], data->r[i]) + data->b;
	data->a = tmp;
	// ft_printf("%u -> g=%u [i = %d] A=%u B=%u C=%u D=%u\n",msg[data->g], data->g, i, data->a, data->b, data->c, data->d);
}


*/

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

unsigned int rightrotate (unsigned int x, unsigned int offset)
{
	return ( x >> offset % 32) | ( x << (32 - offset) % 32);
}

void	init_var(t_var *data)
{
	unsigned int	i;
	unsigned int	tmp[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
	ft_bzero(data, sizeof(t_var));
	data->h0 = 0x6a09e667;
	data->h1 = 0xbb67ae85;
	data->h2 = 0x3c6ef372;
	data->h3 = 0xa54ff53a;
	data->h4 = 0x510e527f;
	data->h5 = 0x9b05688c;
	data->h6 = 0x1f83d9ab;
	data->h7 = 0x5be0cd19;
	i = 0;
	while (i < 64)
	{
		if (i == 0)
			ft_printf("[%2u - %2u]", i, i + 7);
		data->k[i] = tmp[i];
		ft_printf("%#10.10x ", data->k[i]);
		if ((i + 1)% 8 == 0 && i != 63)
			ft_printf("\n[%2u - %2u]", i, i + 8);
		i++;
	}
	ft_printf("\n");
}

char* init_msg(char* msg, t_var *data)
{
	char* new_msg;
	uint64_t new_len;
	uint64_t len;
	unsigned int i;

	len = (uint64_t)ft_strlen(msg);
	data->len = len * 8;
	new_len = 512 * (((data->len + 1) / 512) + 1);
	if (!(new_msg = (char*)malloc(sizeof(char) * new_len)))
		return (0);
	ft_bzero(new_msg, new_len);
	ft_strcpy(new_msg, msg);
	new_msg[len] = 0x80;
	printf("new_msg : %s\n", new_msg);
	((uint64_t*)new_msg)[7] = data->len;
	i = 0;
	//printf("%u", data->len);
	//ft_memcpy(&(new_msg[(new_len / 8) - 8]), &(data->len), 8);
	//ft_printf("%d\n", data->len);
	return (new_msg);
}

#define REV(n) ((n << 24) | (((n>>16)<<24)>>16) | (((n<<16)>>24)<<16) | (n>>24)) 

void	main_while(char *msg, t_var *data, int i)
{
	unsigned int temp1;
	unsigned int temp2;
	unsigned int s0;
	unsigned int s1;
	unsigned int maj;
	unsigned int ch;

	ft_bzero(data->w, sizeof(unsigned int) * 64);
	//ft_memcpy(data->w, msg, 64);
	i = 0;
	//printf("%x %x %x %x\n", ((unsigned char*)data->w)[0],
	//						((unsigned char*)data->w)[1],
	//						((unsigned char*)data->w)[2],
	//						((unsigned char*)data->w)[3]);
	while (i < 64) {
		if (i > 15)
		{
			s0 = rightrotate(data->w[i-15], 7) ^ rightrotate(data->w[i-15], 18) ^ (data->w[i-15] >> 3);
			s1 = rightrotate(data->w[i- 2], 17) ^ rightrotate(data->w[i- 2], 19) ^ (data->w[i- 2] >> 10);
			data->w[i] = data->w[i-16] + s0 + data->w[i-7] + s1;
		}
		else
		{
			data->w[i] = ((unsigned int)msg[i * 4 + 0] << 24| (unsigned int)msg[i * 4 + 1] << 16 |
			(unsigned int)msg[i * 4 + 2] << 8 );//| (unsigned int)msg[i * 4 + 3]);
		}
		i++;
	}
	printf("after memcpy %8.8x\n vs msg : %8.8x\n", *(data->w), *((unsigned int *)msg));
	i = 0;
	while (i < 1)
	{
		s1 = rightrotate(data->e, 6) ^ rightrotate(data->e, 11) ^ rightrotate(data->e, 25);
		ch = (data->e & data->f) ^ ((~data->e) & data->g);
		temp1 = data->h + s1 + ch + data->k[i] + data->w[i];
		s0 = rightrotate(data->a , 2) ^ rightrotate(data->a, 13) ^ rightrotate(data->a, 22);
		maj = (data->a & data->b) ^ (data->a & data->c) ^ (data->b & data->c);
		temp2 = s0 + maj;
		data->h = data->g;
		data->g = data->f;
		data->f = data->e;
		data->e = data->d + temp1;
		data->d = data->c;
		data->c = data->b;
		data->b = data->a;
		data->a = temp1 + temp2;
		printf("t= %2d: %8.8x %8.8x %8.8x %8.8x %8.8x %8.8x %8.8x %8.8x\n", i, data->a, data->b, data->c, data->d, data->e, data->f, data->g, data->h);
		i++;
	}
}

char*	sha256(char* msg, t_var *data)
{
	unsigned int	bit;
	char*			result;
	bit = 0;
	while (bit < data->len)
	{
		data->a = data->h0;
		data->b = data->h1;
		data->c = data->h2;
		data->d = data->h3;
		data->e = data->h4;
		data->f = data->h5;
		data->g = data->h6;
		data->h = data->h7;
		main_while(msg + (int)(bit / 8), data, 0);
		bit += 512;
		data->h0 = data->h0 + data->a;
		data->h1 = data->h1 + data->b;
		data->h2 = data->h2 + data->c;
		data->h3 = data->h3 + data->d;
		data->h4 = data->h4 + data->e;
		data->h5 = data->h5 + data->f;
		data->h6 = data->h6 + data->g;
		data->h7 = data->h7 + data->h;
	}
	if (!(result = (char*)malloc(sizeof(int) * 8)))
		return (0);
	ft_memcpy(result, &(data->h0), 4);
	ft_memcpy(result + 4, &(data->h1), 4);
	ft_memcpy(result + 8, &(data->h2), 4);
	ft_memcpy(result + 12, &(data->h3), 4);
	ft_memcpy(result + 16, &(data->h4), 4);
	ft_memcpy(result + 20, &(data->h5), 4);
	ft_memcpy(result + 24, &(data->h6), 4);
	ft_memcpy(result + 28, &(data->h7), 4);
	ft_strdel(&msg);
	return (result);
}
#include <stdio.h>

int main(int ac, char** av)
{
	char*   msg;
	t_var* data;

	if (!(data = (t_var*)malloc(sizeof(t_var) * 1)))
		return (0);
	init_var(data);
	msg = init_msg(av[1], data);
	msg = sha256(msg, data);
	/*ft_printf("A=%u B=%u C=%u D=%u\n", data->a, data->b, data->c, data->d);*/
	ft_printf("%s",byte_to_hex((void*)msg, 32));
}
//https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Standards-and-Guidelines/documents/examples/SHA256.pdf
//gcc sha256.c -I include libftprintf/libprintf.a; ./a.out "abc"