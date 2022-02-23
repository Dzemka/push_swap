#TARGETS

LIB = libft.a

NAME = push_swap

NAME_BONUS = checker

#DIRECTORIES

PS_DIR = ./push_swap_main/

SRC_DIR = ./src/

OBJ_DIR = ./obj/

LIB_DIR = ./libft/

BNS_DIR = ./push_swap_bonus/

#PATH

SRC_PS_PATH = $(PS_DIR)$(SRC_DIR)

OBJ_PATH = $(PS_DIR)$(OBJ_DIR)

SRC_BNS_PATH = $(BNS_DIR)$(SRC_DIR)

OBJ_BNS_PATH = $(BNS_DIR)$(OBJ_DIR)

#SOURCE_FILES

SRC = push_swap.c algorithms.c fill_stack.c ft_push_b.c ft_push_a.c ft_push_a_utils.c \
		swap.c push.c rotate.c reverse_rotate.c


SRC_BONUS = checker_bonus.c fill_stack_bonus.c moves_bonus.c processing_sort_bonus.c

#HEADERS

PS_HEADER = push_swap.h

PS_BNS_HEADER = checker_bonus.h

#OBJECT_FILES

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

OBJ_BNS = $(addprefix $(OBJ_BNS_PATH), $(SRC_BONUS:%.c=%.o))

#COMMANDS

CC = gcc

RM = rm -rf

#FLAGS

CFLAGS = -Wall -Werror -Wextra

.PHONY	:	all libft bonus clean fclean re

all	: libft $(NAME) bonus

$(NAME)	: $(OBJ_PATH) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIB_DIR)$(LIB)


$(OBJ_PATH)	:
	mkdir -p $(OBJ_PATH)


$(OBJ_PATH)%.o	:	$(addprefix $(SRC_PS_PATH), %.c) $(PS_DIR)$(PS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


bonus	:	$(NAME_BONUS)


$(NAME_BONUS)	:	$(OBJ_BNS_PATH) $(OBJ_BNS) $(LIB_DIR)$(LIB)
	$(CC) -o $@ $(OBJ_BNS) $(LIB_DIR)$(LIB)

$(OBJ_BNS_PATH)	:
		mkdir -p $@

$(OBJ_BNS_PATH)%.o	:	$(addprefix $(SRC_BNS_PATH), %.c) $(BNS_DIR)$(PS_BNS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


libft	:
	make -C $(LIB_DIR) all

clean	:
	$(RM) $(OBJ_PATH) $(OBJ_BNS_PATH)
	make -C $(LIB_DIR) all

fclean	:	clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIB_DIR) fclean

re	:	fclean all