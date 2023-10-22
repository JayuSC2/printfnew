/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:54:07 by juitz             #+#    #+#             */
/*   Updated: 2023/10/22 19:22:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


static int	check_type(const char *format, void *args)
{
	unsigned int	counter;

	counter = 0;
	if	(*format == 'c')
		counter += ft_putchar((int) args);
	else if	(*format == 's')
		counter += ft_putstr((char *) args);
	else if (*format == 'd' || *format == 'i')
		counter += ft_printnbr((int) args);
	else if (*format == 'u')
		counter += ft_print_unsigned((unsigned int) args);
	else if (*format == 'x')
		counter += ft_print_hex_lc((unsigned long long) args);
	else if (*format == 'X')
		counter += ft_print_hex_uc((unsigned long long) args);
	else if (*format == 'p')
		counter += ft_print_pointer((unsigned long long) args);
	/* else if (*format == '%')
		counter += ft_putchar('%'); */ 
	return (counter);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	unsigned int	counter;

	counter = 0;
	if (!str)
		return(-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				counter += check_type(str, va_arg(args, void *));
			else if (*str == '%')
				counter += ft_putchar (*str);
		}
		else 
			counter += ft_putchar (*str);
		str++;
	}
	va_end(args);
	return (counter);
}
#include <stdio.h>

int	main(void)
{
	char *format;
	char *string;
	char character;
	int num;
	int result_ft;
	int result_print;
	// ft_printf(format, 1, 2, 3);

	puts("=== Character: %c ===");
	format = "%c\n";
	character = 'A';
	result_ft = ft_printf(format, character);
	result_print = printf(format, character);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	character = 'B';
	result_ft = ft_printf(format, character);
	result_print = printf(format, character);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("=== String: %s ===");
	format = "%s\n";
	string = NULL;
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	string = "Hello I am a String";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Integer: %d ===");
	format = "%d\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Hexa lower-Cased: %x ===");
	format = "%x\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Hexa UPPER-CASED: %X ===");
	format = "%X\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Multiple-Options (%d%s%X) ===");
	format = "%d%s%X\n";
	string = ": ";
	num = 0;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Percent: %% ===");
	format = "%%\n";
	result_ft = ft_printf(format);
	result_print = printf("%%\n");
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Pointer: %p ===");
	format = "%p\n";
	string = NULL;
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	string = "Im a pointer";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	puts("\n=== Not supported Option and normal text: %y ===");
	format = "Im not supported %y\n";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	puts("\n=== Custom Tests ===");
	format = "%d%d\n";
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	format = NULL;
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	format = "%c %s %p %d %i %u %x %X %%\n";
	num = 42;
	char c = '4';
	string = "printf";
	result_ft = ft_printf(format, c, string, string, num, num, num, num, num);
	result_print = printf(format, c, string, string, num, num, num, num, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n === Check max Pointer ===");
	format = "%p\n";
	result_ft = ft_printf(format, 18446744073709551615ULL);
	result_print = printf(format, 18446744073709551615ULL);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);


}

/* int	main(void)
{
	int				res1 = 0;
	int				res2 = 0;
	char			c = '#';
	char			*str = "Hello_World I love m,y li(f)es";
	int				pnbr = 42;
	void			*ptr = &pnbr; //0;
	int				nbr = 2147483647; //min int
	unsigned int	unbr = 4294967295; //max uint
	char			*format;

	res1 = printf("Og_Character: %c\n", c);
	res2 = ft_printf("ft_Character: %c\n", c);
	printf("Result1 for 'c': %d\n", res1);
	ft_printf("Result2 for 'c': %d\n\n", res2);

	res1 = printf("Og_String: %s\n", str);
	res2 = ft_printf("ft_String: %s\n", str);
	printf("Result1 for 's': %d\n", res1);
	ft_printf("Result2 for 's': %d\n\n", res2);

	res1 = printf("Og_String: %p\n", ptr);
	res2 = ft_printf("ft_String: %p\n", ptr);
	printf("Result1 for 'p': %d\n", res1);
	ft_printf("Result2 for 'p': %d\n\n", res2);

	res1 = printf("Og_Decimal Number and Integer Number: %d and %i\n", nbr, nbr);
	res2 = ft_printf("ft_Decimal Number and Integer Number: %d and %i\n", nbr, nbr);
	printf("Result1 for 'd' and 'i': %d\n", res1);
	ft_printf("Result2 for 'd' and 'i': %d\n\n", res2);

	res1 = printf("Og_Unsigned Integer Number: %u\n", unbr);
	res2 = ft_printf("ft_Unsigned Integer Number: %u\n", unbr);
	printf("Result1 for 'u': %d\n", res1);
	ft_printf("Result2 for 'u': %d\n\n", res2);

	res1 = printf("Og_Hexadecimal Number in uppercase and in lowercase: %X and %x\n", unbr, unbr);
	res2 = ft_printf("ft_Hexadecimal Number in uppercase and in lowercase: %X and %x\n", unbr, unbr);
	printf("Result1 for 'X' and 'x': %d\n", res1);
	ft_printf("Result2 for 'X' and 'x': %d\n\n", res2);

	res1 = printf("Og_Percentage-Character: %%\n");
	res2 = ft_printf("ft_Percentage-Character: %%\n");
	printf("Result1 for '%%': %d\n", res1);
	ft_printf("Result2 for '%%': %d\n\n", res2);

	format = ("%");
	res1 = printf("Og_printf: \t%d\n", printf(format));
	res2 = printf("ft_printf: \t%d\n", ft_printf(format));
	printf("Result1: \t%d\n", res1);
	printf("Result2: \t%d\n\n", res2);

	format = ("%s%");
	res1 = printf("Og_printf: \t%d\n", printf(format, "Hello_World\n"));
	res2 = printf("ft_printf: \t%d\n", ft_printf(format, "Hello_World\n"));
	printf("Result1: \t%d\n", res1);
	printf("Result2: \t%d\n\n", res2);

	format = ("%s%Hello_World\n");
	res1 = printf("Og_printf: \t%d\n", printf(format, "Hello_World\n"));
	res2 = printf("ft_printf: \t%d\n", ft_printf(format, "Hello_World\n"));
	printf("Result1: \t%d\n", res1);
	printf("Result2: \t%d\n\n", res2);

	format = (NULL);
	res1 = printf("Og_printf: \t%d\n", printf(format));
	res2 = printf("ft_printf: \t%d\n", ft_printf(format));
	printf("Result1: \t%d\n", res1);
	printf("Result2: \t%d\n\n", res2);

	return (0);
} */