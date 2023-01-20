NAME		=	minishell

#SRCS		=	main.c debug.c $(shell find srcs/ -name '*.c') #mudar para n ser wildcard
SRCS		= main.c srcs/commands/ms_cd.c \
				srcs/commands/ms_env.c \
				srcs/commands/ms_exit.c \
				srcs/commands/custom_commands/ms_clear.c \
				srcs/commands/custom_commands/change.c \
				srcs/commands/ms_unset.c \
				srcs/commands/ms_export.c \
				srcs/commands/path_commands.c \
				srcs/commands/ms_echo.c \
				srcs/commands/ms_pwd.c \
				srcs/utils/shell_commands.c \
				srcs/utils/ms_export_utils.c \
				srcs/utils/ms_split.c \
				srcs/utils/valid_check.c \
				srcs/utils/path_utils.c \
				srcs/utils/ft_strcmp.c \
				srcs/utils/dict_utils/dict.c \
				srcs/utils/dict_utils/ft_mtrxdo.c \
				srcs/utils/dict_utils/dict_utils.c \
				srcs/utils/dict_utils/dict_utils2.c \
				srcs/utils/dict_utils/antstrcmp.c \
				srcs/utils/ft_mtrxlen.c \
				srcs/utils/ft_charinside.c \
				srcs/utils/ms_readline_utils/ms_readline_utils1.c \
				srcs/utils/ms_readline_utils/ms_readline_utils8.c \
				srcs/utils/ms_readline_utils/ms_readline_utils5.c \
				srcs/utils/ms_readline_utils/ms_readline_utils4.c \
				srcs/utils/ms_readline_utils/ms_readline_utils9.c \
				srcs/utils/ms_readline_utils/ms_readline_utils2.c \
				srcs/utils/ms_readline_utils/ms_readline_utils6.c \
				srcs/utils/ms_readline_utils/ms_readline_utils7.c \
				srcs/utils/ms_readline_utils/ms_readline_utils3.c \
				srcs/utils/ft_strndup.c \
				srcs/utils/info.c \
				srcs/utils/ft_strjoin3.c \
				srcs/command_fork.c \
				srcs/ms_readline.c \
				srcs/frees_and_inits/frees.c \
				srcs/frees_and_inits/rl_free.c \
				srcs/frees_and_inits/prompt.c


OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	./include

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3 #-fsanitize=address

.c.o		:
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME)		:	$(OBJS)
	make bonus -s -C libft
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) ./libft/libft.a -lreadline -L /Users/$(USER)/.brew/opt/readline/li -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME)

all			:	$(NAME)

clean		:
	make -s fclean $@ -C libft
	rm -rf $(OBJS)
	echo "\e[1mObject files deleted\033[0m"

fclean		:	clean
	rm -rf $(NAME)
	echo "\e[1mExecutable files deleted\033[0m"

re			:	fclean all

r:
	@make -s && ./minishell

fc:
	@make -s fclean

va:	re
	valgrind --leak-check=full --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./minishell
	#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --log-file=valgrind-out.txt ./minishell

.PHONY		:	all clean fclean re
