/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 04:11:15 by jotavare          #+#    #+#             */
/*   Updated: 2022/12/29 04:11:15 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Handles SIGUSR1 and SIGUSR2 signals by
// shifting and ORing the bits of a character,
// and sends a confirmation signal back to the sender

// Counter for the number of bits received

// Character being built from the received bits

// Unused parameter

// Shift the character left and set the least
// significant bit to 1 if the signal is SIGUSR1;
// otherwise, shift the character left and set the
// least significant bit to 0

// If 8 bits have been received, print the character and
// reset the counter and character, and send a SIGUSR1
// signal back to the sender as a confirmation

// si_pid is the process ID of the sender

// Send a SIGUSR2 signal back to the sender as a confirmation

// si_pid is the process ID of the sender
void	handler(int sig, siginfo_t *info, void *content)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)content;
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
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Unable to send SIGUSR1\n", 2);
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_putstr_fd("Unable to send SIGUSR2\n", 2);
}

// Print the process ID

// Set up the signal handler for SIGUSR1 and
// SIGUSR2 and wait for signals indefinitely

int	main(void)
{
	struct sigaction	sa_sig;

	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		sa_sig.sa_sigaction = &handler;
		sa_sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			ft_putstr_fd("Unable to send SIGUSR1\n", 2);
		if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
			ft_putstr_fd("Unable to send SIGUSR2\n", 2);
	}
	return (0);
}
