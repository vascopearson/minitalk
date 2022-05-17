/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:58:22 by vserrao-          #+#    #+#             */
/*   Updated: 2022/03/30 17:17:11 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, struct __siginfo *info, void *ucontext)
{
	static int	pid = 0;
	static int	bit = 0;
	static char	c = 0xFF;

	(void)*ucontext;
	if (pid != info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 128 >> bit;
	else
		c ^= 128 >> bit;
	if (++bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %i\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
