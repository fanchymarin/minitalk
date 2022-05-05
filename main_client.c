/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:49:55 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/05/05 16:31:19 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count = 0;

void	bit_received(int signum __attribute__((unused)))
{
	g_count++;
	usleep(100);
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
			{
				error_handling(3);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2))
			{
				error_handling(3);
				exit(1);
			}
		}
		c <<= 1;
		usleep(500);
	}
}

void	print_message(int total)
{
	ft_putnbr_fd(g_count, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(total, 1);
	ft_putstr_fd(" bits sended.\n", 1);
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	rec;

	if (argc != 3)
	{
		error_handling(1);
		exit(1);
	}
	rec.sa_handler = &bit_received;
	sigemptyset(&rec.sa_mask);
	rec.sa_flags = 0;
	if (sigaction(SIGUSR1, &rec, 0))
	{
		error_handling(2);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		char_to_bin(argv[2][i++], pid);
	print_message(ft_strlen(argv[2]) * 8);
	return (0);
}
