/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:32:23 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/20 04:32:24 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// This function processes a single format specifier
// and returns the number of characters printed
int	ft_printf_arg(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnumb(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexadecimal(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

// This function is a custom implementation of the printf function in C

// If a '%' character is encountered, process the following
// format specifier and add the return value to length

// Otherwise, print the character and add 1 to length
int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			length;

	if (!format)
		return (-1);
	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_printf_arg(args, format[i + 1]);
			i++;
		}
		else
			length += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}

// printf example output 
/*
int main()
{
	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf ("Preceding with blanks: %10d \n", 1977);
	printf ("Preceding with zeros: %010d \n", 1977);
	printf ("Some different radices: %d %x %o \n", 100, 100, 100));
	printf ("Some different radices: %#x %#o \n", 100, 100));
	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Width trick: %*d \n", 5, 10);
	printf ("%s \n", "A string");

	ft_printf ("Characters: %c %c \n", 'a', 65);
	ft_printf ("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf ("Preceding with blanks: %10d \n", 1977);
	ft_printf ("Preceding with zeros: %010d \n", 1977);
	ft_printf ("Some different radices: %d %x %o \n", 100, 100, 100));
	ft_printf ("Some different radices: %#x %#o \n", 100, 100));
	ft_printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf ("Width trick: %*d \n", 5, 10);
	ft_printf ("%s \n", "A string");
	return 0;
}
*/
