NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./build

INCLUDES = -I$(INCLUDESDIR) -I$(LIBFT_PATH)/includes
SRCS = ft_printf.c arg_parser.c flags_parser.c \
	   width_parser.c precision_parser.c length_parser.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ar rcs $@ $(OBJS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@$(RM) -r $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all

test: fclean $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) main.c -L. -lftprintf $(LIBFT_FLAGS) -o $@ -g
	@./$@
	@$(RM) $@
	@make fclean
