/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:40:41 by knomura           #+#    #+#             */
/*   Updated: 2025/09/15 20:13:16 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "server.h"

// void	handler(int sig)
// {
// 	static unsigned char 	c;
// 	static int				bit = 0;

// 	c = c << 1;
// 	if (sig == SIGUSR2)
// 		c = c | 1;
// 	bit++;

// 	if (bit == 8)
// 	{
// 		write(1, &c, 1);
// 		bit = 0;
// 		c = 0;
// 	}
// }

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1,"0",1);
	else if (sig == SIGUSR2)
		write(1,"1",1);
	else if (sig == SIGINT)
		write(1, "HELLO!\n", 7);
	else
		write(1, "2", 1);
}

int main()
{
	int pid;
	pid = getpid();
	printf("PID:%d\n", pid);

	// struct sigaction sa;
	// sa.sa_handler = handler;
	// sa.sa_flags = 0;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);

	printf("%d %d\n",SIGUSR1, SIGUSR2);

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, handler);


	while (1)
	{
		pause();
	}
	return (0);
}
