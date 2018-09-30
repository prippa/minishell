# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2017/11/13 14:21:04 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
# FLAGS		= 	-Wall -Werror -Wextra
COMP_FLAGS	=	-g -lreadline
CC			=	gcc

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_MSH	=	minishell.h messages.h

#-------------------------- Source files ---------------------------------------
C_MSH		= 	main.c msh_reset.c msh_exit.c msh_free.c msh_parse_line.c


OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_MSH:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_MSH 	= 	$(addprefix $(DIR_INC), $(HEAD_MSH))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(COMP_FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_MSH)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files minishell ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files minishell ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
