/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:55:38 by codespace         #+#    #+#             */
/*   Updated: 2023/10/22 17:12:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int  ptr_len(unsigned long int num)
{
    unsigned int    counter;
    
    while (num != 0)
    {
        num /= 16;
        counter++;
    }
    return(counter);
}

void    put_ptr(unsigned long int num)
{
    if (num >= 16)
    {   
        put_ptr (num % 16);
        put_ptr (num / 16);
    }
    else
    {
        if (num <= 9)
            ft_putchar(num + '0');
        else
            ft_putchar(num - 10 + 'a');
    }
}

int ft_print_pointer(unsigned long int num)
{
    if (num == 0)
        return (write(1, "(nil)", 6));
    else
    {
        write(1, "0x", 2);
        put_ptr(num);
    }
    return (ptr_len(num));
}
