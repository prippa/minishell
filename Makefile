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

NAME			=	minishell
# FLAGS			= 	-Wall -Werror -Wextra
READLINE_FLAG	=	-lreadline
CC				=	gcc -g

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_CMDS	=	$(DIR_SRC)msh_commands/
DIR_MLP		=	$(DIR_SRC)msh_line_parser/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_MSH	=	minishell.h messages.h commands.h

#-------------------------- Source files ---------------------------------------
C_MSH		= 	main.c msh_exit.c msh_free.c msh_execute_cmd.c\
				msh_utility.c msh_env_get.c

C_CMDS		=	msh_cd.c msh_echo.c msh_env.c msh_setenv.c msh_unsetenv.c

C_MLP		=	msh_line_parser.c

OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_MSH:.c=.o) $(C_CMDS:.c=.o) \
				$(C_MLP:.c=.o))

INC 		= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_MSH 	= 	$(addprefix $(DIR_INC), $(HEAD_MSH))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(READLINE_FLAG) $(LIBFT) 
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_MSH)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#msh_commands
$(DIR_OBJ)%.o: $(DIR_CMDS)%.c $(INC_MSH)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#msh_line_parser
$(DIR_OBJ)%.o: $(DIR_MLP)%.c $(INC_MSH)
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
