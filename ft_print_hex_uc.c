/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:00:35 by juitz             #+#    #+#             */
/*   Updated: 2023/10/22 16:23:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num)
{
	int counter;
	
	counter = 0;
	while (num != 0)
	{
		num /= 16;
		counter++;
	}
	return (counter);
}

void	ft_put_hexa_uc(unsigned int num)
{

	if (num >= 16)
		{
			ft_put_hexa_uc(num / 16);
			ft_put_hexa_uc(num % 16);
		}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'A');
	}
}

int ft_print_hex_uc(unsigned int num)
{
    if (num == 0)
        return (ft_putchar('0'));
    ft_put_hexa_uc(num);
        return(hex_len(num));
}