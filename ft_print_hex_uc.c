/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:00:35 by juitz             #+#    #+#             */
/*   Updated: 2023/10/23 14:50:44 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num)
{
	int	counter;

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

int	ft_print_hex_uc(unsigned int num)
{
	if (num == 0)
		return (ft_putchar('0'));
	ft_put_hexa_uc(num);
	return (hex_len(num));
}
