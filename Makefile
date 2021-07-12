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
SRCS = ft_printf.c utils.c arg_parser.c flags_parser.c \
	   width_parser.c precision_parser.c format_current.c \
	   format_int.c apply.c apply_int.c format_uint.c \
	   apply_uint.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

BONUS_SRCDIR = ./bonus
BONUS_SRCS = ft_printf_bonus.c utils_bonus.c arg_parser_bonus.c flags_parser_bonus.c \
			 width_parser_bonus.c precision_parser_bonus.c length_parser_bonus.c format_current_bonus.c \
			 format_int_bonus.c apply_bonus.c apply_int_bonus.c format_uint_bonus.c  \
			 apply_uint_bonus.c
BONUS_OBJS := $(addprefix $(OBJDIR)/,$(BONUS_SRCS:.c=.o))
BONUS_SRCS := $(addprefix $(BONUS_SRCDIR)/,$(BONUS_SRCS))

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

bonus: $(LIBFT) $(BONUS_OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(BONUS_OBJS)

test: fclean $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf $(LIBFT_FLAGS) -o $@ -g
	@./$@
	@$(RM) $@
	@make fclean
