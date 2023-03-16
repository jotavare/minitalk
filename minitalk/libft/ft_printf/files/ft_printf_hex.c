/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:13:51 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/20 06:13:55 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// This function returns the number of hexadecimal
// digits required to represent an unsigned integer

// Initialize the length to 0

// Divide the number by 16 repeatedly until it becomes 0
// and increment the length by 1 each time

// Return the length
int	ft_hexlen(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		num = num / 16;
		length++;
	}
	return (length);
}

// This function converts an unsigned integer
// to a hexadecimal string and prints it to the console

// If the number is greater than or equal to 16,
// recursively print the hexadecimal representation of num / 16
// followed by the hexadecimal representation of num % 16

// If the number is less than or equal to 9,
// print the corresponding ASCII character (0-9)

// If the format is 'x', print the corresponding ASCII character (a-f)

// If the format is 'X', print the corresponding ASCII character (A-F)
void	ft_printhex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_printhex(num / 16, format);
		ft_printhex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

// This function converts an unsigned integer
// to a hexadecimal string, prints it to the console,
// and returns the length of the string

// If the number is 0, print "0"
// to the console and return 1 (the length of "0")

// Convert the number to a hexadecimal string and print it to the console

// Return the length of the hexadecimal string
int	ft_puthexadecimal(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhex(num, type);
	return (ft_hexlen(num));
}
