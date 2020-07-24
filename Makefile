
NAME = ft_ls
S_PATH = srcs/
E_FLAGS = -Wall -Werror -Wextra
LIBFT = lib/
SRC = $(S_PATH)initialize.c $(S_PATH)main.c $(S_PATH)recursive.c \
	  $(S_PATH)error_handling.c $(S_PATH)files.c\
	  $(S_PATH)helpers.c $(S_PATH)memory.c $(S_PATH)lists.c $(S_PATH)display.c \
	  $(S_PATH)display2.c $(S_PATH)sorting.c \


#OBJ = $(SRC:$(S_PATH)%.c=%.o)

$(NAME):
		@make -C lib/
		@gcc $(E_FLAGS) $(SRC) -o $(NAME) $(LIBFT)libft.a

all : $(NAME)

clean:
	@make -C lib/ clean
	@rm -rf $(OBJ)

fclean:
	@make -C lib/ fclean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)
