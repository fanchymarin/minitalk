/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:50:51 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/05/05 17:42:31 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int signum, siginfo_t *info,
void *ucontext __attribute__((unused)))
{
	static char	c = 0;
	static int	i = 8;

	if (signum == SIGUSR1)
		c = (c ^ 1);
	if (i != 1)
		c <<= 1;
	if (!--i)
	{
		write(1, &c, 1);
		c = 0;
		i = 8;
	}
	kill(info->si_pid, SIGUSR1);
}

void	print_message(void)
{
	ft_putstr_fd("Server up and running. PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	act;

	print_message();
	act.sa_sigaction = &bin_to_char;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) || sigaction(SIGUSR2, &act, 0))
		error_handling(2);
	while (1)
		pause();
	return (0);
}
