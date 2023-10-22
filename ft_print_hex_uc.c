/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:00:35 by juitz             #+#    #+#             */
/*   Updated: 2023/10/22 17:57:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	hex_len(int num)
{
	int counter;
	
	while (num != 0)
	{
		num /= 16;
		counter++;
	}
	return (counter);
}

static void	ft_put_hexa(unsigned int num)
{
	if (num >= 16)
		{
			ft_put_hexa(num % 16);
			ft_put_hexa(num / 16);
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
	{
        return (write(1, 0, 1));
	}
    ft_put_hexa(num);
        return(hex_len(num));
}