NAME = libft.a
OBJDIR = obj
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(OBJ)))
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
