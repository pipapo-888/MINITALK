/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:40:35 by knomura           #+#    #+#             */
/*   Updated: 2025/09/20 15:33:17 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, 12);
		else
			kill(pid, 10);
		usleep(200);
		i--;
	}
}

int main(int argc, char **argv)
{
	int		pid_id;
	char	*str;
	int		i;

	if (argc != 3)
		return (1);

	pid_id = atoi(argv[1]);
	str = argv[2];
	i = 0;

	while(str[i])
	{
		send_char(pid_id, str[i]);
		i++;
	}
}
