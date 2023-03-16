/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:19:42 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/28 23:19:43 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Handles SIGUSR1 and SIGUSR2 signals by shifting
// and ORing the bits of a character

// Counter for the number of bits received

// Character being built from the received bits

// Shift the character left and set the least
// significant bit to 1 if the signal is SIGUSR1;
// otherwise, shift the character left and set the
// least significant bit to 0

// If 8 bits have been received, print the
// character and reset the counter and character
void	handler(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

// Print the process ID

// Set up the signal handlers and wait for signals indefinitely
int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
