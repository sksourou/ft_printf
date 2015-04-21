# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sksourou </var/mail/sksourou>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 00:15:17 by sksourou          #+#    #+#              #
#    Updated: 2015/03/09 02:51:36 by sksourou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -I./include/
SRC = \
	  convert.c convert2.c convert3.c\
	  utils.c utils2.c utils3.c\
	  is_infos.c search_infos.c search_infos2.c\
	  printf.c base.c\
	  add_width.c add_prec.c add_flag.c add_flag2.c\
	  wchar.c colors.c init.c\
	  ft_atoi.c ft_isalpha.c ft_isdigit.c\
	  ft_itoa.c ft_itoa_long.c ft_putchar.c\
	  ft_putstr.c ft_strcmp.c ft_strlen.c\
	  ft_strrev.c ft_uitoa.c ft_uitoa_long.c\
	  wstrlen.c\

OBJ = $(SRC:.c=.o)
	SRCDIR	= ./src/
	OBJDIR	= ./obj/
	INCDIR	= ./include/
	SRCS	= $(addprefix $(SRCDIR), $(SRC))
	OBJS	= $(addprefix $(OBJDIR), $(OBJ))
	INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n\t \033[32mIndexing lib ..\033[0m\n"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a create."
	@echo "\n\t \033[32m[All Fine's]\033[0m\n"

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@echo "\nRM *.o.. \t      \033[32mOK BITCH!\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "RM libftprintf.a..    \033[32mOK BITCH!\033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
