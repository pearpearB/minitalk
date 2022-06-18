# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 14:31:30 by daekim            #+#    #+#              #
#    Updated: 2022/06/18 16:56:15 by jabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER =		server
CLIENT =		client

SERVER_BONUS =	server_bonus
CLIENT_BONUS =	client_bonus

LIBFT =			libft/libft.a

SRCS_S =		server.c 
SRCS_C =		client.c

SRCS_S_BONUS =	./bonus/server_bonus.c 
SRCS_C_BONUS =	./bonus/client_bonus.c

OBJS_S =		server.o 
OBJS_C =		client.o

OBJS_S_BONUS =	./bonus/server_bonus.o 
OBJS_C_BONUS =	./bonus/client_bonus.o

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror # -fsanitize=address -g3



all :			$(SERVER) $(CLIENT)

$(SERVER) :	$(OBJS_S) $(LIBFT)
			cp $(LIBFT) ./
			$(CC) $(CFLAGS) -L./libft -lft -o $(SERVER) $(OBJS_S)

$(CLIENT) : $(OBJS_C) $(LIBFT)
			cp $(LIBFT) ./
			$(CC) $(CFLAGS) -L./libft -lft -o $(CLIENT) $(OBJS_C)

$(LIBFT) :		
			$(MAKE) -C ./libft all


bonus :				$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) :	$(OBJS_S_BONUS) $(LIBFT)
					cp $(LIBFT) ./
					$(CC) $(CFLAGS) -L./libft -lft -o $(SERVER_BONUS) $(OBJS_S_BONUS)

$(CLIENT_BONUS) :	$(OBJS_C_BONUS) $(LIBFT)
					cp $(LIBFT) ./
					$(CC) $(CFLAGS) -L./libft -lft -o $(CLIENT_BONUS) $(OBJS_C_BONUS)	

clean :
			rm -f $(OBJS_S) $(OBJS_C)
			rm -f $(OBJS_S_BONUS) $(OBJS_C_BONUS)
			$(MAKE) -C ./libft clean

fclean :	clean
			rm -f libft.a
			$(MAKE) -C ./libft fclean
			rm -f $(SERVER) $(CLIENT)
			rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re : 		fclean all bonus

.PHONY :	all clean fclean re bonus