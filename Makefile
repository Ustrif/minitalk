# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 16:53:40 by raydogmu          #+#    #+#              #
#    Updated: 2025/01/18 17:11:14 by raydogmu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = ft_printf.c
CLIENTFILE = client.c
SERVERFILE = server.c
OFILES = $(CFILE:.c=.o)

NAME = minitalklib.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	ar r $(NAME) $(OFILES)
	$(CC) $(CLIENTFILE) $(NAME) $(CFLAGS) -o client
	$(CC) $(SERVERFILE) $(NAME) $(CFLAGS) -o server

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) client server

re: fclean all

.PHONY: all bonus clean fclean re