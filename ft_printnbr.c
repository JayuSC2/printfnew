/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:22:19 by juitz             #+#    #+#             */
/*   Updated: 2023/10/16 09:42:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

int	nbr_len(int num)
{
	int	counter;

	counter = 0;
	if (num == 0)
		return (1);
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		counter++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static void	ft_putnbr(int num)
{
	char	nb;
	
	if (num < 0 && num > -2147483648)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num >= 0 && num < 10)
	{
		nb = num + '0';
		write(1, &nb, 1);
	}
	if (num >= 10 && num <= 2147483647)
	{
		ft_printnbr(num / 10);
		ft_printnbr(num % 10);
	}
}

int	ft_printnbr(int num)
{
	ft_putnbr(num);
	return (nbr_len(num));
}
	/* int	ft_printnbr(int num, unsigned int *counter)
{
	
	char	nb;
	
	if (num < 0 && num > -2147483648)
	{
		write(1, "-", 1);
		num *= -1;
		*counter = *counter + 1;
	}
	if (num >= 0 && num < 10)
	{
		nb = num + '0';
		write(1, &nb, 1);
		*counter = *counter + 1; 
	}
	if (num >= 10 && num <= 2147483647)
	{
		ft_printnbr(num / 10, counter);
		ft_printnbr(num % 10, counter);
	}
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter = 11;
		return (11);
	}
	return (*counter);
} */
/* #include <stdio.h>
int	main(void)
{
	int	counter = 0;
	
	ft_printnbr (2147483647, &counter);
	write (1, "\num", 1);
	printf("%d", counter);
	ft_printnbr (-100, &counter);
	write (1, "\num", 1);
	ft_printnbr (35340503, &counter);
	write (1, "\num", 1);
	ft_printnbr (-2147483648, &counter);
	write (1, "\num", 1);
	printf("%d", counter);*/
