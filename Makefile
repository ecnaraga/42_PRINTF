# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:55:00 by galambey          #+#    #+#              #
#    Updated: 2023/06/23 16:03:08 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g
PATH_LIBFT = ./LIBFT

################################### SOURCES ###################################

CONVERSION_DIR         =	conversion_specifier/
CONVERSION_SRCS        =	ft_print_char.c \
							ft_print_int.c \
							ft_print_unsignedint.c \
							ft_print_lowhexa.c \
							ft_print_upphexa.c \
							ft_print_str.c \
							ft_print_ptr.c

FLAGS_DIR        		=	flags_plus_precision/
FLAGS_SRCS      		=	check_flag.c \
							manage_arg.c

PRINTF_DIR        		=   printf/
PRINTF_SRCS       		=   ft_printf.c \
							do_print.c

UTILS_DIR          		=   utils/
UTILS_SRCS         		=   ft_atoi_mode.c

############################# HANDLE DIRECTORIES ##############################

SRCS_DIR          =     srcs/

SRCS			=	$(addprefix $(CONVERSION_DIR), $(CONVERSION_SRCS)) \
					$(addprefix $(FLAGS_DIR), $(FLAGS_SRCS)) \
					$(addprefix $(PRINTF_DIR), $(PRINTF_SRCS)) \
					$(addprefix $(UTILS_DIR), $(UTILS_SRCS))

OBJS_DIR 		= 	.objs/

OBJS_NAMES 		= 	$(SRCS:.c=.o)

OBJS_FOLDER		=	$(addprefix $(OBJS_DIR), $(CONVERSION_DIR) \
                        $(FLAGS_DIR) \
                        $(PRINTF_DIR) \
                        $(UTILS_DIR))

OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

DEPS := $(OBJS:.o=.d)

#################################### RULES ####################################

CC = cc
FLAGS = -Wall -Wextra -Werror -g
PATH_LIBFT = ./LIBFT

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(PATH_LIBFT)
	cp ./LIBFT/libft.a ./libftprintf.a
	ar -rcs $@ $(OBJS)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -I $(PATH_LIBFT) -o $@

clean :
	make -sC $(PATH_LIBFT) clean
	rm -rf $(OBJS_DIR)

fclean : clean
	make -sC $(PATH_LIBFT) fclean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re