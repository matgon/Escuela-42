# Name of the final static library
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

# Sources
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

# All
all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	@cp $(LIBFT_LIB) temp_libft.a
	@ar x temp_libft.a
	@ar rcs $(NAME) $(OBJS) *.o
	@rm -f temp_libft.a *.o
	@echo "✅ $(NAME) creado correctamente."

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft if not yet built
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything including the .a
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

.PHONY: all clean fclean re
