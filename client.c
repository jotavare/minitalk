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

// Sends the specified message to the specified process using SIGUSR1 and SIGUSR2 signals
void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	// Initialize variables
	i = 0;
	c = 0;

	// Iterate through each character of the message
	while (*str)
	{
		c = *(str);

		// Iterate through each bit of the current character
		while (i < 8)
		{
			// If the current bit is 1, send SIGUSR1 signal; otherwise, send SIGUSR2 signal
			if (c << i & 0b10000000)
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_printf("Unable to send SIGUSR1\n");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_printf("Unable to send SIGUSR2\n");
					exit(EXIT_FAILURE);
				}
			}
			i++;
			// Sleep for 100 microseconds between each signal
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	// Validate the number of arguments
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		// Convert the server ID (PID) to an integer and send the message using the signal_action function
		signal_action(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
