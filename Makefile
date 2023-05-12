# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/12 13:16:14 by yitoh         #+#    #+#                  #
#    Updated: 2023/05/12 13:16:56 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC = cc
SRC = 
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = ./obj/
CFLAG = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = fdf
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAG) $^ -o $@

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAG) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all
