/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:48:49 by juitz             #+#    #+#             */
/*   Updated: 2023/10/23 14:55:48 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printnbr(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_print_hex_lc(unsigned int num);
int		ft_print_hex_uc(unsigned int num);
int		ft_print_unsigned(unsigned int n);
int		ft_print_pointer(unsigned long long ptr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);

#endif