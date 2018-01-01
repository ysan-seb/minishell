# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 07:19:36 by ysan-seb          #+#    #+#              #
#    Updated: 2017/05/18 14:27:25 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	main.c \
			minishell_title.c \
			get_next_line/get_next_line.c \
			split.c \
			parse_argv.c \
			exc_cmd.c \
			exc_bui.c \
			builtin_echo.c \
			builtin_env.c \
			builtin_cd.c \
			tools.c \

OBJS	=	main.o \
			minishell_title.o \
			get_next_line/get_next_line.o \
			split.o \
			parse_argv.o \
			exc_cmd.o \
			exc_bui.o \
			builtin_echo.o \
			builtin_env.o \
			builtin_cd.o \
			tools.o \

CC	=	gcc

CFLAGS	= -Wall -Werror -Wextra 

HEADER = -I./

LIBFT = ./libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

.SILENT:
		
$(NAME)	:	$(OBJS)
		@make -C libft/
		@$(CC) -o $(NAME) $(OBJS) $(HEADER) $(LIBFT)
		@echo "\033[38;5;208mLibft\033[0m : Is fully compiled\c\r"
		@echo "\n\033[38;5;208mMinishell\033[0m : Ready"

clean	:
		@make -C libft/ clean
		@$(RM) $(OBJS)
		@echo "\033[38;5;208mMinishell\033[0m : Clean"

fclean:
		@make -C libft/ fclean
		@$(RM) $(NAME) $(OBJS)
		@echo "\033[38;5;208mMinishell\033[0m : Full clean"

re	:	fclean all