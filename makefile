# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knomura <knomura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/19 19:38:49 by knomura           #+#    #+#              #
#    Updated: 2025/09/28 18:11:06 by knomura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

PRINTF = PRINTF/printf.a

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(PRINTF)
	$(CC) $(SERVER_OBJ) $(PRINTF) -o $@

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) -o $@

$(PRINTF):
	make -C PRINTF

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
