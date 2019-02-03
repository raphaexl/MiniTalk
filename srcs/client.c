/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:41:10 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/03 18:07:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_sendsignal(char c, int pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		kill(pid, (c & (1 << i)) ? SIGUSR1 : SIGUSR2);
		usleep(100);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		pid;

	if (argc != 3)
		ft_error();
	pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_sendsignal(argv[2][i], pid);
		i++;
	}
	ft_sendsignal(argv[2][i], pid);
	return (0);
}
