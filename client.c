/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:40:35 by knomura           #+#    #+#             */
/*   Updated: 2025/09/28 19:41:52 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t flag = 0;

void	handler(int sig)
{
	(void)sig;
	flag = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		pause();
	}
}

int main(int argc, char **argv)
{
	int		pid_id;
	char	*str;
	int		i;

	if (argc != 3)
		return (1);
	signal(SIGUSR1, handler);
	pid_id = atoi(argv[1]);
	if (kill(pid_id, 0)== -1 || pid_id < 1)
		return (1);
	str = argv[2];
	i = 0;
	while(str[i])
	{
		send_char(pid_id, str[i]);
		i++;
	}
}
