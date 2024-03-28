###############################
#            COLORS      	  #
###############################
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
BLUE = \033[34m
MAGENTA = \033[35m
ORANGE = \033[1;38;5;208m
STOP_COLOR = \033[0m
###############################
#         COMPILATION   	  #
###############################
CC = cc
GCC = cc 
CFLAGS = -Wall -Wextra -Werror -g
###############################
#           COMMANDS     	  #
###############################
RM = rm -rf
###############################
#           SRCS/OBJS    	  #
###############################
LIBFTDIR = libft/
LIBFTLIB = libft/libft.a

SRC = ft_general_utils.c ft_val_utils.c mov_push.c \
		mov_revrotate.c mov_rotate.c \
		mov_swap.c srt_sorting_calculation.c \
		srt_sorting_operations.c st_list_utils.c \
		st_stack_definition.c st_stack_utils.c \

SRC_DIR = ./source/

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJDIR = objs/
NAME = push_swap

INPUT = 1 3 5 -10 -50 87 6
###############################
#     BONUS =>  SRCS/OBJS     #
###############################
BONUS_OBJDIR = bonus/bonus_objs/
BONUS_NAME = checker

BONUS_SRC = bonus/checker_bonus.c bonus/ft_utils_bonus.c \
			bonus/ft_val_utils_bonus.c bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c bonus/mov_bonus.c

BONUS_OBJ = $(addprefix $(BONUS_OBJDIR), $(BONUS_SRC:bonus/%.c=%.o))
#######################################################################
#                		     PUSH_SWAP - RULES       			      #
#######################################################################
#main rule
all : $(NAME)

#create a directory for the objects
$(OBJDIR) :
	@echo "$(YELLOW)[!] $(STOP_COLOR)CREATING DIRECTORY FOR OBJECTS"
	mkdir $@
	@echo "$(GREEN)[✔]$(STOP_COLOR) CREATED $@ DIRECTORY"

#compile the project
$(NAME) : $(OBJ) $(LIBFTLIB)
	@echo "$(YELLOW)[!] $(STOP_COLOR)COMPILING PROJECT "
	$(CC) $(CFLAGS) $(OBJ) $(SRC_DIR)push_swap.c $(LIBFTLIB) -o $(NAME)
	@echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)OK$(STOP_COLOR)"

#compile the objects and display a message for the first time created
#or in case of modification
$(OBJDIR)%.o: $(SRC_DIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ -n "$(shell find $< -newer $(OBJDIR)$*.o -print -quit)" ]; then \
		echo "$(GREEN)[✔]$(STOP_COLOR) $(ORANGE)UPDATE OF $< DONE$(STOP_COLOR)"; \
	else \
		echo "$(YELLOW)[!]$(STOP_COLOR) $(ORANGE)Creating $<$(STOP_COLOR)"; \
    	$(CC) $(CFLAGS) -c $< -o $@; \
    fi

#Create lib for libft
$(LIBFTLIB) : $(LIBFTDIR)
	echo "$(YELLOW)[!] $(STOP_COLOR)COMPILING LIBFT"
	make -C $(LIBFTDIR) bonus
	make -C ./libft/ft_printf

#clean the .o objects
clean :
	echo "$(YELLOW)[!] $(STOP_COLOR)CLEANING"
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)
	echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)CLEAN DONE.$(STOP_COLOR)"

#clean the .o objects, the objs folder and the project file.
fclean :
	echo "$(YELLOW)[!] $(STOP_COLOR)FULL CLEANING"
	$(RM) $(NAME) $(OBJDIR)
	make fclean -C $(LIBFTDIR)
	echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)FULL CLEANING DONE. $(STOP_COLOR)"

#refresh the project
re : fclean all
	echo "$(GREEN)[✔]$(STOP_COLOR) $(MAGENTA)REFRESH DONE.$(STOP_COLOR)"

#######################################################################
#                		       BONUS - RULES   		    		      #
#######################################################################
#compile the bonus
bonus : $(BONUS_NAME)

#Create directory for the bonus objects
$(BONUS_OBJDIR) :
	@echo "$(YELLOW)[!] $(STOP_COLOR)CREATING DIRECTORY FOR BONUS OBJECTS"
	@mkdir $@
	@echo "$(GREEN)[✔]$(STOP_COLOR) CREATED $@ DIRECTORY"

# Rule to compile bonus objects
$(BONUS_OBJDIR)%.o : bonus/%.c | $(BONUS_OBJDIR)
	@echo "$(YELLOW)[!] $(STOP_COLOR)COMPILING $< "
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[✔]$(STOP_COLOR) COMPILED $<"

$(BONUS_NAME) : $(BONUS_OBJDIR) $(BONUS_OBJ) $(OBJ) $(LIBFTLIB)
	@echo "$(YELLOW)[!] $(STOP_COLOR)COMPILING BONUS "
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ) $(LIBFTLIB) -o bonus/$(BONUS_NAME)
	@echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)OK$(STOP_COLOR)"

bonus_clean :
	echo "$(YELLOW)[!] $(STOP_COLOR)CLEANING BONUS"
	$(RM) $(BONUS_OBJDIR)
	make clean -C $(LIBFTDIR)
	echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)BONUS CLEAN.$(STOP_COLOR)"

bonus_fclean :
	echo "$(YELLOW)[!] $(STOP_COLOR)BONUS FULL CLEANING"
	$(RM) bonus/$(BONUS_NAME) $(BONUS_OBJDIR)
	make fclean -C $(LIBFTDIR)
	echo "$(GREEN)[✔]$(STOP_COLOR) $(BLUE)BONUS FULL CLEANING DONE. $(STOP_COLOR)"
#######################################################################
#                		       EXTRA RULES  		    		      #
#######################################################################
#rule to valgrind
valgrind : $(NAME)
	$(GCC) $(CFLAGS) $(OBJ) $(LIBFTLIB) -o $(NAME)
	valgrind -s --leak-check=full ./$(NAME) $(INPUT)
	make clean
	./push_swap $(INPUT)

.SILENT :
