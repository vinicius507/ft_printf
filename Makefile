NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./build

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

INCLUDES = -I$(INCLUDESDIR) -I$(LIBFT_PATH)/includes
SRCS = ft_printf.c ft_dprintf.c ft_sprintf.c ft_asprintf.c utils.c arg_parser.c flags_parser.c \
	   width_parser.c precision_parser.c length_parser.c format_current.c format_int.c \
	   apply.c apply_int.c format_uint.c  apply_uint.c format_str.c apply_str.c \
	   format_char.c apply_char.c format_ptr.c apply_ptr.c format_hexa.c apply_hexa.c \
	   format_literal.c apply_literal.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $@
	@ar rcs $@ $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(OBJDIR)/%.o: $(BONUS_SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) -r $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all
