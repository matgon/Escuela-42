# Nombre del ejecutable
NAME = rush-02
# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
# Archivos fuente y objetos
SRC = main.c dict.c solve.c str.c utilities.c aux.c
OBJ = $(SRC:.c=.o)
# Regla principal
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
# Reglas de limpieza
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all