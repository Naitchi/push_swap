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
		op_swap.c \
		bubble_sort.c \
		is_stack_sorted.c \
		bucket_ins_sort.c \
		buckets_management.c \
		utils_rotate.c \
		utils_libft.c \
		complex.c \
		index.c \
		adaptive.c
DIR_PF = ft_printf/
SRCS_PF = $(addprefix $(DIR_PF), ft_printf.c ft_printint.c ft_printhexa.c ft_printchar.c ft_printstr.c \
	ft_printunsint.c ft_printptr.c ft_unsitoa.c ft_itoa.c)
DIR_OBJS = objects/
DIR_OBJS_PF = objects/ft_printf/
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))
OBJS_PF = $(addprefix $(DIR_OBJS), $(SRCS_PF:.c=.o))
DEPS = $(OBJS:.o=.d)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)  $(OBJS_PF)

$(DIR_OBJS)%.o : %.c | $(DIR_OBJS) $(DIR_OBJS_PF)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $@

$(DIR_OBJS_PF):
	mkdir -p $@

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)	

re: fclean $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
