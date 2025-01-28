/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaraaga <tkaraaga@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:59:30 by tkaraaga          #+#    #+#             */
/*   Updated: 2023/08/25 12:13:47 by tkaraaga         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sighandler(int signum)
{
	static int	c = -1;
	static int	sigusr2ctr;
	static int	counter;

	if (signum == SIGUSR1)
	{
		c++;
		sigusr2ctr = 0;
	}
	if (signum == SIGUSR2)
	{
		if (sigusr2ctr == 1)
		{
			ft_printf("%c", ((char)counter));
			counter = 0;
			return ;
		}
		if (sigusr2ctr == 0)
		{
			counter *= 10;
			counter += c;
			c = -1;
		}
		sigusr2ctr++;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %u\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
}
