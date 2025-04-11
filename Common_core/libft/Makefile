# Nombre de la librería
NAME = libft.a

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Buscar todos los archivos .c en la carpeta actual
SRC = $(wildcard *.c)

# Generar archivos .o correspondientes
OBJ = $(SRC:.c=.o)

# Regla por defecto
all: $(NAME)

# Construir la librería
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilar cada .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJ)

# Limpiar todo
fclean: clean
	rm -f $(NAME)

# Reconstrucción
re: fclean all

.PHONY: all clean fclean re
