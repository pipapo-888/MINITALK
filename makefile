# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 19:38:49 by knomura           #+#    #+#              #
#    Updated: 2025/09/19 19:49:26 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = CC
CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@
