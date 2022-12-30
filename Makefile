# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 03:50:25 by jotavare          #+#    #+#              #
#    Updated: 2022/12/29 03:50:27 by jotavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a

CC = cc
CCFLAGS = cc -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
		${CCFLAGS} ${OBJS_SERVER} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT} libft/libft.a -o ${CLIENT}

$(LIBFT):
		${MAKE} -C ./libft

bonus: ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS} ${LIBFT}
		${CCFLAGS} ${OBJS_SERVER_BONUS} libft/libft.a -o ${SERVER}
		${CCFLAGS} ${OBJS_CLIENT_BONUS} libft/libft.a -o ${CLIENT}

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_SERVER_BONUS} ${OBJS_CLIENT_BONUS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all