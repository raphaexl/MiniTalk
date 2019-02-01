/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:31:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/02/01 22:14:56 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int waiting = 0;

void	ft_sendsignal(char c, int pid)
{
	int i = 0;

	while (waiting == 1)
		pause();
	while (i < 8)
	{
		kill(pid, (c & (1 << i)) ? SIGUSR1 : SIGUSR2);
		waiting = 1;
		i++;
	}
}

int main(int argc, char **argv)
{
	char str[] = "GsE7mY81UbutNtXI4BdiJelOuC8gxSA4Avro8cXmi0XNFcPriNVu8iIc9irWS2xE3XWUvKrgMSV5aQ9Kiv2fUrnJXGD3EZtrhKhT";
	int i = 0;
	if (argc < 2)
		return (1);
	int fd = atoi(argv[1]);
	while (str[i])
	{
		ft_sendsignal(str[i], fd);
		i++;
	}
	return (0);
}
