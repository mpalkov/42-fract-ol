NAME := a.out

SRCS := 1main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	cc -Wall -Werror -Wextra -Imlx -c $< -o $@ -g3

$(NAME): $(OBJS)
	cc $(OBJS) -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@