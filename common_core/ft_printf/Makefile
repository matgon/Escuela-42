NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)
OBJDIR = obj

SRC = ft_printf_utils.c ft_printf_functions_1.c ft_printf_functions_2.c ft_printf.c
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(OBJ)))

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	@cp $(LIBFT_LIB) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "✅ $(NAME) creado correctamente."

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
