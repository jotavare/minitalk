/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:19:28 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/28 23:19:30 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Sends the specified message to the specified
// process using SIGUSR1 and SIGUSR2 signals

// Initialize variables

// Iterate through each character of the message

// Iterate through each bit of the current character

// If the current bit is 1, send SIGUSR1 signal;
// otherwise, send SIGUSR2 signal

// Sleep for 100 microseconds between each signal
void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

// Validate the number of arguments

// Convert the server ID (PID) to an integer and
// send the message using the signal_action function

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal_action(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
