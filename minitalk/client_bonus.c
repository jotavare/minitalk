/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 04:11:06 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/29 04:11:07 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Sends the specified message to the specified
// process using SIGUSR1 and SIGUSR2 signals

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
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Unable to send SIGUSR1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Unable to send SIGUSR2\n");
			}
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

// Handles the SIGUSR1 signal by printing a message

// Validate the PID argument

// Validate the number of arguments and the message argument

// Set up the signal handler for SIGUSR1 and SIGUSR2

// Set up the signal handler for SIGUSR1 and SIGUSR2
void	handler(int sig)
{
	static int	message_printed = 0;

	if (!message_printed)
	{
		if (sig == SIGUSR1)
		{
			ft_printf("The signal was received successfully.\n");
			message_printed = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					i;

	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			if (argv[1][i++] == '\0')
				ft_printf("Invalid PID.\n");
	if (argc != 3 || argv[2] == 0)
	{
		ft_printf("Number of arguments invalid or the message is empty.\n");
		ft_printf("Try again.\n");
	}
	else
	{
		sa_sig.sa_handler = &handler;
		sa_sig.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa_sig, NULL);
		sigaction(SIGUSR2, &sa_sig, NULL);
		signal_action(ft_atoi(argv[1]), argv[2]);
	}
	return (EXIT_SUCCESS);
}
