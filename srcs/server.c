/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:22:03 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/03 18:04:37 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_str	g_str;

void	usr1(int sig)
{
	(void)sig;
	g_str.letter |= 1 << g_str.offset;
	g_str.offset++;
}

void	usr2(int sig)
{
	(void)sig;
	g_str.letter |= 0 << g_str.offset;
	g_str.offset++;
}

int		main(void)
{
	ft_putnbr(getpid());
	g_str.letter = 0;
	g_str.offset = 0;
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	while (g_str.letter != 1)
	{
		g_str.offset = 0;
		g_str.letter = 0;
		while (g_str.offset < 8)
			pause();
		write(1, &g_str.letter, 1);
	}
	return (0);
}
