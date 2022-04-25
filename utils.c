/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:12:58 by fmarin-p          #+#    #+#             */
/*   Updated: 2022/04/26 00:40:15 by fmarin-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n += 48;
		write (fd, &n, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, &(*s), 1);
		++s;
	}
}

int	ft_atoi(const char *str)
{
	int	num;
	int	neg;

	num = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			neg = -1;
		++str;
	}
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (*str - 48);
		if (*str - 48 != num % 10 && num != -2147483648)
		{
			if (neg == -1)
				return (0);
			return (-1);
		}
		++str;
	}
	return (num * neg);
}
