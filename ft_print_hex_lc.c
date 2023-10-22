/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:46:20 by codespace         #+#    #+#             */
/*   Updated: 2023/10/22 17:56:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int    hex_len(int num)
{
    int counter;

    while (num != 0)
    {
         num /= 16;
         counter++;
    }
    return (counter);
}

void    ft_put_hexa(unsigned int num)
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
            ft_putchar(num - 10 + 'a');
    }
}

int ft_print_hex_lc(unsigned int num)
{
    if (num == 0)
    {
        return (write(1, 0, 1));
    }
    ft_put_hexa(num);
        return(hex_len(num));
}

/* 
void    *ft_put_hexa(unsigned int num, const char *format)
{
    if (num >= 16)
        {
            ft_put_hexa(num % 16, *format);
            ft_put_hexa(num / 16, *format);
        }
    else
    {
        if (num <= 9)
            ft_putchar(num + '0');
        else
        {
            if (*format == 'x')
                ft_putchar(num - 10 + 'a');
            if (*format == 'X')
                ft_putchar(num - 10 + 'A');
        }
    }
} */