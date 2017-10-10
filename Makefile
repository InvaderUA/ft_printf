# **************************************************************************** #
#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klut <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 13:31:46 by klut              #+#    #+#              #
#    Updated: 2016/12/22 20:58:52 by klut             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = convertion_buffering.c\
	  convertion_parcers.c\
	  ft_memory_type_parcing.c\
	  digits_processing.c\
	  ft_processing.c\
	  ft_printf.c\
	  ft_bufiller.c\
	  ft_casting.c\
	  ft_format_regime.c\
	  ft_itoa_base.c\
	  ft_ndd_processing.c\
	  supportive_functions.c\
	  unsigned_processing.c\
	  letters_processing.c\
	  supportive_functions2.c

OBJ = $(SRC:.c=.o)

LIBOBJ = libft/*.o

CFLAGS = -c -Wall -Wextra -Werror

LIB = make -C libft/

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) all
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

%.o: ./%.c
	gcc -o $@ -c $<

clean:
	$(LIB) clean
	rm -f $(OBJ)

fclean: clean
	$(LIB) fclean
	rm -f $(NAME)

re: fclean all
