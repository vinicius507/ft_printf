NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

INCLUDESDIR = ./includes
SRCDIR = ./src
OBJDIR = ./build

INCLUDES = -I$(INCLUDESDIR) -I$(LIBFT_PATH)/includes
SRCS = ft_printf.c 
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR)/,$(SRCS))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L$(LIBFT_PATH) -lft

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
