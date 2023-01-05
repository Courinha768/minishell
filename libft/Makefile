# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 17:56:33 by aappleto          #+#    #+#              #
#    Updated: 2023/01/05 11:33:01 by aappleto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HDRS = libft.h

NAME = libft.a

RM = rm -rf

GCC = gcc

AR = ar -crs

FLAGS = -Wall -Wextra -Werror

.c.o:
	$(GCC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(HDR)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS) $(HDRS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

re: clean fclean all

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:     clean
	$(RM) $(NAME)
.PHONY: all clean fclean re bonus
