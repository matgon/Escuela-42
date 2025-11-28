NAME = libft.a
OBJDIR = obj

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(notdir $(OBJ)))

BONUS_SRC = $(wildcard *_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJ := $(addprefix $(OBJDIR)/, $(notdir $(BONUS_OBJ)))

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: all $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
