# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lubaujar </var/mail/lubaujar>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 00:15:17 by lubaujar          #+#    #+#              #
#    Updated: 2015/03/02 17:19:26 by lubaujar         ###   ########.fr        #
#    Updated: 2015/02/20 07:58:23 by lubaujar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
SRC = convert.c\
	  convert2.c\
	  utils.c\
	  utils2.c\
	  utils3.c\
	  is_infos.c\
	  search_infos.c\
	  search_infos2.c\
	  printf.c\
	  base.c\
	  add_width.c\
	  add_prec.c\
	  add_flag.c\
	  add_flag2.c\
	  wchar.c\
	  init.c\
	  ft_atoi.c\
	  ft_atoi_long.c\
	  ft_itoa.c\
	  ft_itoa_long.c\
	  ft_uitoa.c\
	  ft_uitoa_long.c\
	  ft_strlen.c\
	  ft_strrev.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  wstrlen.c

OBJ = $(SRC:.c=.o)

INC = -I./includes/

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(INC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n\t \033[32m[All Fine's]\033[0m\n"

clean:
	@echo "\nRM *.o.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(OBJ)
	@$(RM) *.o

fclean: clean
	@echo "RM libftprintf.a..    \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

exec:
	@echo "\033[37mgcc *.c -I./includes/ ..\033[0m"
	@echo "  \033[37m..exec ./a.out\033[0m\n"
	@gcc *.c -g $(FLAGS) -I./includes/
	@echo "\033[31m./a.out\033[m\n"
	@./a.out

.PHONY: all clean fclean re exec
