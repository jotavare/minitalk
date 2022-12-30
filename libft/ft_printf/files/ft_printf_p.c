/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 07:02:39 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/20 07:02:42 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// This function counts the number of digits in a
// hexadecimal representation of an unsigned long long integer

// Divide num by 16 until it becomes 0
static int	ft_countpointer(unsigned long long prt)
{
	int	count;

	count = 0;
	while (prt != 0)
	{
		count++;
		prt = prt / 16;
	}
	return (count);
}

// This function prints the hexadecimal representation
// of an unsigned long long integer to stdout

// If num is greater than or equal to 16,
// recursively print the hexadecimal representation of num / 16 and num % 16

// Otherwise, if num is less than or equal to 9,
// print num as a single digit

// '0' ASCII value is 48

// Otherwise, print num as a hexadecimal digit

// 'a' ASCII value is 97

// Return the number of digits in the hexadecimal representation of num
int	ft_printpointer(unsigned long long prt)
{
	if (prt >= 16)
	{
		ft_printpointer(prt / 16);
		ft_printpointer(prt % 16);
	}
	else
	{
		if (prt <= 9)
			ft_putchar(prt + 48);
		else
			ft_putchar(prt - 10 + 'a');
	}
	return (ft_countpointer(prt));
}

// This function prints the hexadecimal representation of a pointer to stdout

// If ptr is 0, print "(nil)" and return 5

// Print "0x" and increment len by 2

// Print the hexadecimal representation of ptr and
// increment len by the number of digits
int	ft_putpointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += ft_printpointer(ptr);
	return (len);
}
