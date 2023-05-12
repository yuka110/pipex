# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 14:35:44 by yitoh         #+#    #+#                  #
#    Updated: 2023/05/11 09:56:18 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
	  ft_tolower.c ft_toupper.c ft_memcpy.c ft_memchr.c ft_strlcpy.c ft_strlcat.c \
	  ft_strncmp.c ft_strchr.c ft_strnstr.c ft_strrchr.c ft_memset.c ft_bzero.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_atoi.c ft_strlcat.c ft_calloc.c \
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_striteri.c\
	  ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	  ft_split.c\
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
	  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
	  ft_printf_char.c ft_printf_hex.c ft_printf.c\
	  get_next_line.c get_next_line_utils.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = ./obj/
CFLAG = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -crs $@ $^

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAG) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(OBJ) a.out
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: clean fclean all bonus
