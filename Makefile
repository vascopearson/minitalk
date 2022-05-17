SERVER = server
CLIENT = client
HEADER = minitalk.h
PRINTF = ./printf/libftprintf.a
PRINTF_DIR = ./printf
CC = gcc
INC = -I. -I$(PRINTF_DIR)
FLAGS = -Wall -Wextra -Werror
RM = rm -f



SRC_C = client.c
SRC_S = server.c
 

OBJS = $(SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(PRINTF)
	$(CC) $(FLAGS) $(SRC_S) $(PRINTF) $(INC) -o $(SERVER)

$(CLIENT): $(PRINTF)
	$(CC) $(FLAGS) $(SRC_C) $(PRINTF) $(INC) -o $(CLIENT)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean: 
	$(RM) $(CLIENT) $(SERVER)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus 

