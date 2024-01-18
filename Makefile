################################
#            COLORS            #
################################
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[34m
MAGENTA = \033[35m
COLOR_RESET = \033[0m

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

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJDIR = objs/
NAME = push_swap

INPUT = 1 3 5 -10 -50 87 6
################################
#            rules             #
################################
all : $(NAME)

$(OBJDIR) :
	echo "$(YELLOW)[!] $(COLOR_RESET)CREATING DIRECTORY FOR OBJECTS"
	mkdir $@
	echo "$(GREEN)[✔]$(COLOR_RESET) CREATED $@ DIRECTORY"

$(NAME) : $(OBJ) $(LIBFTLIB)
	echo "$(YELLOW)[!] $(COLOR_RESET)COMPILING PROJECT "
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	echo "$(GREEN)[✔]$(RESET) $(BLUE)COMPILATION DONE$(RESET)"

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

#Create lib for libft
$(LIBFTLIB) : $(LIBFTDIR)
	echo "$(YELLOW)[!] $(COLOR_RESET)COMPILING LIBFT"
	make -C $(LIBFTDIR) bonus
	make -C ./libft/ft_printf

clean :
	echo "$(YELLOW)[!] $(COLOR_RESET)CLEANING"
	$(RM) $(OBJ)
	make clean -C $(LIBFTDIR)
	echo "$(GREEN)[✔]$(RESET) $(BLUE)CLEAN DONE.$(RESET)"

fclean :
	echo "$(YELLOW)[!] $(COLOR_RESET)FULL CLEANING"
	$(RM) $(NAME) $(OBJ)
	make fclean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)
	echo "$(GREEN)[✔]$(RESET) $(BLUE)FULL CLEANING DONE. $(RESET)"

re : fclean all
	echo "$(GREEN)[✔]$(RESET) $(MAGENTA)REFRESH DONE.$(RESET)"

valgrind : $(NAME)
	$(GCC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	valgrind -s --leak-check=full ./$(NAME) $(INPUT)
	make clean
	./push_swap $(INPUT)

.SILENT :
