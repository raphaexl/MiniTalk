/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:22:14 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/01 22:36:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

char	letter = 0;
int 	offset = 0;

void	usr1(int sig)
{
	letter |= 1 << offset;
	offset++;
}

void	usr2(int sig)
{
	letter |= 0 << offset;
	offset++;
}

int main(void)
{
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	while (letter != 1)
	{
		offset = 0;
		letter = 0;
		while (offset < 8)
			pause();
		putchar(letter);
	}
	return (0);
}
