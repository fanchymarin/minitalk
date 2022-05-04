/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:49:55 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/05/04 19:50:34 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_received(int signum __attribute__((unused)))
{
	static int	i = 8;

	ft_putstr_fd("[=]", 1);
	if (!--i)
	{
		ft_putstr_fd(" Byte received\n", 1);
		i = 8;
	}
	usleep(300);
}

int	char_to_bin(char c, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c & 256)
		{
			if (kill(pid, SIGUSR1))
			{
				error_handling(3);
				return (-1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2))
			{
				error_handling(3);
				return (-1);
			}
		}
		c <<= 1;
		usleep(300);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	rec;

	if (argc != 3)
	{
		error_handling(1);
		return (-1);
	}
	rec.sa_handler = &bit_received;
	sigemptyset(&rec.sa_mask);
	rec.sa_flags = 0;
	if (sigaction(SIGUSR1, &rec, 0))
	{
		error_handling(2);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		if (char_to_bin(argv[2][i++], pid))
			return (-1);
	return (0);
}
