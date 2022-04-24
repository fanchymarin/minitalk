/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:28:47 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/24 18:00:12 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bin(char c, int pid)
{
	int	i;

	pid = 0;
	i = 8;
	while(i--)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("Number of arguments invalid.\n", 1);
		return (0);
	}
	i = 0;
	while (argv[2][i])
		char_to_bin(argv[2][i++], ft_atoi(argv[1]));
	return (0);
}
