/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:55:38 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 14:53:26 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_len(unsigned long long num)
{
	unsigned int	counter;

	counter = 0;
	while (num != 0)
	{
		num /= 16;
		counter++;
	}
	return (counter);
}

void	put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		put_ptr (num / 16);
		put_ptr (num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
		counter += (write(1, "(nil)", 5));
	else
	{
		counter += write(1, "0x", 2);
		put_ptr(ptr);
		counter += ptr_len(ptr);
	}
	return (counter);
}
