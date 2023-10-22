/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:48:40 by codespace         #+#    #+#             */
/*   Updated: 2023/10/22 16:23:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	unsigned_len(unsigned int num)
{
	int	counter;
	
	counter = 0;
	while (num > 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}
void	ft_put_unsigned(unsigned int n)
{
	char	nb;

	if (n < 10)
	{
		nb = n + '0';
		write(1, &nb, 1);
	}
	else if (n < 4294967295)
	{
		ft_print_unsigned(n / 10);
		ft_print_unsigned(n % 10);
	}
}

int ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (unsigned_len(n));
}

/* int	ft_print_unsigned(unsigned int n, unsigned int *counter)
{
	char	nb;

	if (n >= 0 && n < 10)
	{
		nb = n + '0';
		write(1, &nb, 1);
		*counter = *counter + 1;
	}
	if (n >= 10 && n <= 4294967295)
	{
		ft_print_unsigned(n / 10, counter);
		ft_print_unsigned(n % 10, counter);
	}
	return (*counter);
} */

/* #include <stdio.h>
int main(void)
{
	int	counter = 0;
	
    ft_print_unsigned(-4, &counter);
	printf("%s", "\n");
	printf("%d", counter);
	printf("%s", "\n");
	printf("%u",-4);
} */
