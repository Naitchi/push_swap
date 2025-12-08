CC = cc 
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP
SRCS = error_handler.c \
	   input.c \
	   list_utils.c \
	   op_push.c \
	   op_reverse_rotate.c \
	   op_rotate.c \
	   op_swap.c \
	   push_swap.c \
	   parsing.c

DIR_OBJS = objects/
OBJS = $(SRCS:.c=.o)
OBJECTS = $(addprefix $(DIR_OBJS))
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
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)	

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
