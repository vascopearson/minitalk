/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:58:26 by vserrao-          #+#    #+#             */
/*   Updated: 2022/03/30 17:17:15 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary_msg(int pid, char *msg)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (msg[i])
	{
		while (bit < 9)
		{
			if (msg[i] & 128 >> bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(42);
			if (bit == 8)
			{
				bit = 0;
				break ;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Client: invalid args!");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_binary_msg(pid, argv[2]);
	return (0);
}
