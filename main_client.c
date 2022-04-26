/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:28:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/26 11:39:44 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_recieved(int signum)
{
	if (signum != 10)
		return ;
	ft_putstr_fd("[=]", 1);
}

void	char_to_bin(char c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 256)
		{
			if (kill(pid, SIGUSR1))
				ft_putstr_fd("Bit not sended\n", 1);
		}
		else
			if (kill(pid, SIGUSR2))
				ft_putstr_fd("Bit not sended\n", 1);
		c <<= 1;
		usleep(30);
	}
}

int	main(int argc, char **argv)
{
	int				i;
	int				pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [Message]\n", 1);
		return (0);
	}
	signal(SIGUSR1, bit_recieved);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		char_to_bin(argv[2][i++], pid);
	write(1, "\n", 1);
	return (0);
}
