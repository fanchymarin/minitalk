# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarin-p <fmarin-p@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 19:32:17 by fmarin-p          #+#    #+#              #
#    Updated: 2022/05/05 17:43:54 by fmarin-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

all: client server
	@./server

client: main_client.c utils.c
	@gcc $(CFLAGS) -o client $^

server: main_server.c utils.c
	@gcc $(CFLAGS) -o server $^

clean:
	@rm -rf client server

fclean: clean

re: fclean all

.PHONY: all clean fclean re
