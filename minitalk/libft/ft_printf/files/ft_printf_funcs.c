/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 05:46:34 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/20 05:46:38 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// This function prints a single character to the console

// Write the character 'c' to the console
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// This function prints a string to the console
// and returns the length of the string if successful

// If the string is NULL, print "(null)" to the console
// and return 6 (the length of "(null)")

// Calculate the length of the string

// Write the string to the console
// and return the length of the string
int	ft_putstr(char *str)
{
	int		len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

// This function converts an integer to a string,
// prints the string to the console,
// and returns the length of the string if successful

// Convert the integer 'n' to a string

// Print the string to the console

// Free the memory used by the string

// Return the length of the string
int	ft_putnumb(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
