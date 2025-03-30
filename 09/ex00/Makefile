# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schmitzi <schmitzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:29:42 by mgeiger-          #+#    #+#              #
#    Updated: 2024/12/11 16:46:21 by mgeiger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc

CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
RM			=	rm -f

RED			=	\e[0;91m
GREEN		=	\e[0;92m
YELLOW		=	\e[0;33m
RESET		=	\e[0m

FILES		=	main \
				BitcoinExchange

SRC_DIR 	= 	./
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJ_DIR		= 	obj/
OBJ			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(OBJ_DIR)%.o: %.cpp $(wildcard *.hpp)
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

all:	$(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling exercise$(RESET)"
	@$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)
	@echo "$(GREEN)Exercise built$(RESET)"

clean:
	@$(RM) $(OBJ)
	@if [ -d "obj" ]; then \
		rm -r obj/; \
	fi
	@echo "$(RED)Removed objects$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(RED)All files cleaned$(RESET)"

re:		fclean all
	clear ;
	@echo "$(GREEN)Files cleaned and program re-compiled$(RESET)"

start: fclean all
	clear ;
	@./$(NAME)

.PHONY:		all clean fclean re
