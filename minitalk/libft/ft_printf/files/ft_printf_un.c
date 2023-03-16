/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:35:34 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/20 06:35:35 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// This function returns the number of digits
// required to represent an unsigned integer

// Initialize the length to 0

// Divide the number by 10 repeatedly until it becomes 0
// and increment the length by 1 each time

// Return the length
int	ft_length_num(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

// This function converts an unsigned integer to a string

// Get the number of digits required to represent the integer

// Allocate memory for the string

// If the memory allocation failed, return NULL

// Add a null terminator to the end of the string

// Convert the integer to a string by repeatedly dividing it by 10
// and adding the corresponding ASCII character (0-9) to the string

// Return the string
char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length_num(n);
	num = (char *)malloc((len + 1) * sizeof(char *));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

// This function prints an unsigned integer to the console
// and returns the number of characters printed

// Initialize the length to 0

// If the number is 0, print "0" and return 1
// Convert the integer to a string

// Print the string and increment the length by the number of characters printed

// Free the memory allocated for the string

// Return the length
int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write (1, "0", 1);
	else
	{
		num = ft_utoa(n);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
