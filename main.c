/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:17:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/09/08 12:46:03 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void writeSpecified(int output, char* content)
{
    write(output, content, ft_strlen(content));
}

int main(int ac, char** av)
{
    return (0);
}