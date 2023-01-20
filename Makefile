NAME		=	minishell

SRCS		=	main.c debug.c $(shell find srcs/ -name '*.c') #mudar para n ser wildcard
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	./include

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3 #-fsanitize=address

.c.o		:
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME)		:	$(OBJS)
	@make bonus -s -C libft
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) ./libft/libft.a -lreadline -L /Users/$(USER)/.brew/opt/readline/li -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME)

all			:	$(NAME)

clean		:
	make -s fclean $@ -C libft
	rm -rf $(OBJS)
	echo "\e[1mObject files deleted\033[0m"

fclean		:	clean
	@rm -rf $(NAME)
	@echo "\e[1mExecutable files deleted\033[0m"

re			:	fclean all

r:
	@make -s && ./minishell

fc:
	@make -s fclean

va:	re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./minishell

.PHONY		:	all clean fclean re
