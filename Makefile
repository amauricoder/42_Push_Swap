################################
#         COMPILATION          #
################################
CC = cc
GCC = cc 
CFLAGS = -Wall -Wextra -Werror -g

################################
#           COMMANDS           #
################################
RM = rm -rf

################################
#   SOURCES - OBJECTS - NAME   #
################################
LIBFTDIR = libft/
LIBFTLIB = libft/libft.a

SRC = push_swap.c ft_val_utils.c \
	  ft_general_utils.c st_list_utils.c st_stack_utils.c \
	  mov_swap.c mov_rotate.c mov_revrotate.c \
	  mov_push.c srt_sorting_operations.c \
	  st_stack_definition.c srt_sorting_calculation.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

INPUT = 1 2 3 4 5
################################
#            rules             #
################################
all : $(NAME)

$(NAME) : $(OBJ) $(LIBFTLIB)
	echo "\033[1;32mCOMPILING\033[0m"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	make clean

#Create lib for libft
$(LIBFTLIB) : $(LIBFTDIR)
	make -C $(LIBFTDIR) bonus
	make -C ./libft/ft_printf

clean :
	echo "\033[1;33mCLEANING\033[0m"
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)

fclean :
	echo "\033[1;31mFULL CLEANING\033[0m"
	$(RM) $(NAME) $(OBJ)
	make fclean -C $(LIBFTDIR)

re : fclean all

valgrind : $(NAME)
	$(GCC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	valgrind -s --leak-check=full ./$(NAME) $(INPUT)
	make clean
	./push_swap $(INPUT)


.SILENT :
