LIBFT = .libft/libft.a
NAME = libftprintf.a
HEADER = ft_printf.h
INCLUDES = -I.inc
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = src/ft_eval.c src/ft_print_dec_int.c src/ft_init_format.c\
	src/ft_print_char_str.c src/ft_print_dec_int.c src/ft_print_hexa.c\
	src/ft_uitoa.c src/ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean: 
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean ${NAME}

bonus: $(NAME)

.PHONY: all clean fclean re bonus 
