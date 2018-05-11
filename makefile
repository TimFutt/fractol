NAME = fractol

SRC = srcs/main.c \
			srcs/event.c \
			srcs/draw.c \
			srcs/calc.c

OBJ = main.o \
			event.o \
			draw.o \
			calc.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
		@make -C ./libft/
		@gcc -c $(FLAGS) $(SRC)
		@echo "\033[31m[COMPILATION]\033[0m"
		@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME) $(MLX)
		@echo "\033[36m[FRACTOL CREATED]\033[0m"
		@mkdir objs
		@mv main.o objs
		@mv event.o objs
		@mv draw.o objs
		@mv calc.o objs

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[32m[CLEANING LIBFT OBJECTS]\033[0m"
	@rm -rf objs
	@echo "\033[32m[CLEANING FRACTOL OBJECTS]\033[0m"

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)
	@@echo "\033[32m[CLEANING FRACTOL]\033[0m"

re : fclean all
