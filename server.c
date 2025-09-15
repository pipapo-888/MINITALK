/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:40:41 by knomura           #+#    #+#             */
/*   Updated: 2025/09/15 17:34:44 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "server.h"

void	handler(int sig)
{
	static unsigned char 	c;
	static int				bit = 0;

	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;

	bit++;

	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int main()
{
	int pid;
	pid = getpid();
	printf("PID:%d\n", pid);

	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = 0;

	printf("%d %d\n",SIGUSR1, SIGUSR2);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}
