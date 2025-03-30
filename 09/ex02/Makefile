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

NAME 		= PmergeMe
CXX 		= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
RM 			= rm -f

RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;33m
RESET 		= \033[0m

FILES 		= main \
			MergeDeque \
			MergeVector \
			PmergeMe

SRC_DIR = ./
SRC = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling exercise$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Exercise built$(RESET)"

clean:
	@$(RM) $(OBJ)
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	fi
	@echo "$(RED)Removed objects$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)All files cleaned$(RESET)"

re: fclean all
	@clear 
	@echo "$(GREEN)Files cleaned and program re-compiled$(RESET)"

.PHONY: all clean fclean re
