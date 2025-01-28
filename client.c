/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:05:58 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/08/25 15:19:51 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	signal_sender(int times, int pid)
{
	while (times >= 0)
	{
		usleep(250);
		kill(pid, SIGUSR1);
		times--;
	}
	usleep(250);
	kill(pid, SIGUSR2);
}

void	up(int counter, int pid)
{
	if (counter > 99)
	{
		signal_sender((counter / 100), pid);
		counter %= 100;
	}
	signal_sender((counter / 10), pid);
	counter %= 10;
	signal_sender(counter, pid);
	usleep(250);
	kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	sign;
	int		i;
	int		j;

	i = 0;
	j = 2;
	if (argc >= 3)
	{
		pid = ft_atoi(argv[1]);
		if (argv[2][0] == 0)
			return (0);
		while (argv[j])
		{
			up((argv[j][i++]), pid);
			if ((argv[j][i]) == '\0')
			{
				j++;
				i = 0;
			}
		}
	}
}
