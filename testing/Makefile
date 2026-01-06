CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP
SRCS = 	bench.c \
		compute_disorder.c \
		error_handler.c \
		flags.c \
		ft_split.c \
		input.c \
		list_utils.c \
		parsing.c \
		push_swap.c \
		op_push.c \
		op_reverse_rotate.c \
		op_rotate.c \
		op_swap.c
DIR_OBJS = objects/
OBJS = $(addprefix $(DIR_OBJS),$(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(DIR_OBJS)%.o : %.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $@

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)	

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
