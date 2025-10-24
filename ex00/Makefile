CC = g++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -fsanitize=address
SRC_FILES = main.cpp ScalarConverter.cpp MyException.cpp TypeFactory.cpp
SRC_DIR = src
OBJ_DIR = obj

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

INC = -Iinc
NAME = ex00

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)

