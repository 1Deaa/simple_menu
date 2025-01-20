NAME = main_menu

FILES = main.c

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -lXext -lX11 -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all fclean clean re