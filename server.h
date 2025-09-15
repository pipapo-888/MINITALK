/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:30:29 by knomura           #+#    #+#             */
/*   Updated: 2025/09/15 13:25:07 by knomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_putstr_fd(char *s, int fd);

#endif
