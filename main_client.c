/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:28:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/05/03 19:08:00 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
void	bit_received(int signum)
{
	static int	i = 8;

	if (signum != SIGUSR1)
		return ;
	ft_putstr_fd("[=]", 1);
	if (!--i)
	{
		ft_putstr_fd(" Character received\n", 1);
		i = 8;
	}
}
*/
void	char_to_bin(char c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 256)
		{
			if (kill(pid, SIGUSR1))
				ft_putstr_fd("[x]", 1);
		}
		else
			if (kill(pid, SIGUSR2))
				ft_putstr_fd("[x]", 1);
		c <<= 1;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
//	struct sigaction	rec;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [Message]\n", 1);
		return (0);
	}
/*	rec.sa_handler = &bit_received;
	sigemptyset(&rec.sa_mask);
	rec.sa_flags = 0;
	sigaction(SIGUSR1, &rec, 0);*/
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		char_to_bin(argv[2][i++], pid);
//		usleep(350);
	}
//	sleep(1);
	return (0);
}
