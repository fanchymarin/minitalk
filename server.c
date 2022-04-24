/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:27:11 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/24 18:01:50 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	bin_to_char(int signum)
{
	static char	c = 0;
	static int	i = 8;

	if (signum == 10)
		c = (c ^ 1);
	else
		c <<= 1;
	c <<= 1;
	if (--i)
	{
		write(1, &c, 1);
		c = 0;
		i = 8;
	}
}

int	main(void)
{
	int		pid;
	char	c;

	pid = getpid();
	//Tengo que cambiar el printf
	printf("Server up and running. PID: %d\n", pid);
	signal(SIGUSR1, bin_to_char);
	signal(SIGUSR2, bin_to_char);
	while(1)
	{
		sleep(30);
		printf("...\n");
	}
	return (0);
}
