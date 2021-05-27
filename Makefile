NAME = ./push_swap
NAME_S = ./checker

FLAGS = -Wall -Wextra -Werror

DIR_SRC = ./src/
DIR_INC = ./includes/
DIR_OBJ = ./obj/
DIR_SRC_S = ./src/
DIR_INC_S = ./includes/
DIR_OBJ_S = ./objs/

INC = ./includes/push_swap.h

SRC_FILES = main.c				\
			find_median.c		\
			split_on_stack.c	\
			ft_atoi.c			\
			ft_algo.c			\
			ft_verif_sort.c		\
			ft_multi_av.c		\
			ft_sort.c			\
			ft_sort_a_five.c	\
			ft_sort_a_five_bis.c\
			ft_av.c				\
			ft_ss.c				\
			ft_pb.c				\
			ft_pa.c				\
			ft_rr.c				\
			ft_rrr.c			\
			ft_finder.c			\

SRC_FILES_S = checker.c			\
			find_median.c		\
			split_on_stack.c	\
			ft_atoi.c			\
			ft_algo.c			\
			ft_verif_sort.c		\
			ft_multi_av.c		\
			ft_sort.c			\
			ft_sort_a_five.c	\
			ft_sort_a_five_bis.c\
			get_next_line.c		\
			get_next_line_utils.c\
			ft_av.c				\
			ft_ss.c				\
			ft_pb.c				\
			ft_pa.c				\
			ft_rr.c				\
			ft_rrr.c			\
			ft_finder.c			\

SRC = $(addprefix $(DIR_SRC), $(SRC_FILES))
OBJ = $(addprefix $(DIR_OBJ), $(SRC_FILES:.c=.o))
SRC_S = $(addprefix $(DIR_SRC_S), $(SRC_FILES_S))
OBJ_S = $(addprefix $(DIR_OBJ_S), $(SRC_FILES_S:.c=.o))

all: $(NAME) $(NAME_S)

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "Compilation of \033[1m$@\033[0m  \n"
	@gcc $(OBJ) -o $(NAME)
	@echo "PUSH_SWAP CREATED"

$(NAME_S): $(DIR_OBJ_S) $(OBJ_S)
	@printf "Compilation of \033[1m$@\033[0m\n"
	@gcc $(OBJ_S) -o $(NAME_S)
	@echo "CHECKER CREATED"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ_S):
	@mkdir -p $(DIR_OBJ_S)

$(DIR_OBJ)%.o:$(DIR_SRC)%.c $(INC)
	@gcc $(FLAGS)  -I $(DIR_INC) -o $@ -c $<

$(DIR_OBJ_S)%.o:$(DIR_SRC_S)%.c $(INC)
	@gcc $(FLAGS)  -I $(DIR_INC) -o $@ -c $<

clean:
	@rm -Rf $(DIR_OBJ)
	@rm -Rf $(DIR_OBJ_S)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_S)
	@echo "\nPUSH_SWAP AND CHECKER DELETED\n"

re: fclean all

.PHONY: all clean fclean re

