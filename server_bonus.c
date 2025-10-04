/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:40:41 by knomura           #+#    #+#             */
/*   Updated: 2025/10/04 17:31:20 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char 	c;
	static int				bit = 0;

	(void)context;
	c = c << 1;
	if (sig == SIGUSR2)
		c = c | 1;
	bit++;

	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	int pid;
	pid = getpid();
	ft_printf("PID:%d\n", pid);

	struct sigaction sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		pause();
	}
	return (0);
}
