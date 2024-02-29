# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 09:22:21 by esimpson          #+#    #+#              #
#    Updated: 2024/02/27 15:37:56 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_split.c ft_isdigit.c ft_atol.c ft_putchar_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_putstr_fd.c	
      
OBJ = $(SRC:%.c=%.o)

CFLAGS =  -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ) 
	
%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@    

clean:
	@rm -rf $(OBJ) 
    
fclean: clean
	@rm -rf $(NAME)

re: fclean all 

.PHONY: clean fclean all re 
