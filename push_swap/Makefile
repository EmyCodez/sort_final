# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 15:42:01 by esimpson          #+#    #+#              #
#    Updated: 2024/02/29 16:01:03 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft

SRCS_PATH = srcs

COM_PATH = $(SRCS_PATH)/commands

LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = includes

SRC_FILES = $(SRCS_PATH)/push_swap.c $(SRCS_PATH)/sort_three_plus.c  $(SRCS_PATH)/sort_utils.c \
		    $(SRCS_PATH)/stack_utils.c $(SRCS_PATH)/valid_utils.c  $(SRCS_PATH)/init_stack.c \
		    $(SRCS_PATH)/sort_stack.c $(COM_PATH)/push.c $(COM_PATH)/reverse_rotate.c \
		    $(COM_PATH)/rotate.c $(COM_PATH)/swap.c 

 	  	
SRC_OBJ = $(SRC_FILES:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	@make -C $(LIBFT_PATH) all
	@$(CC) $(CFLAGS) $(SRC_OBJ) -I$(INCLUDE) $(LIBFT) -o $(NAME)
	@echo "SUCCESSFULLY MADE $(words $(SRC_OBJ)) object files"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(SRC_OBJ) 

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) 

re: fclean $(NAME) 

.PHONY:	all clean fclean re 