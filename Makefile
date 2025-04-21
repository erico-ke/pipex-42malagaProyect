NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -rf

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./libs -I $(LIBFT_PATH)  -I ./includes

SRCS =	$(wildcard $(SRCDIR)/*.c)

OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)
SRCDIR = src/
OBJDIR = obj/

all : $(LIBFT) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean

fclean:
	$(RM) obj $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
