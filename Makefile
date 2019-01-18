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
DIR_LP		=	$(DIR_SRC)line_parser/
DIR_LP_CMD	=	$(DIR_LP)lp_commands/
DIR_OBJ		= 	./obj/
DIR_LIB		=	./libft/
DIR_LIB_INC	=	$(DIR_LIB)includes/
LIBFT		=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
HEAD_BASE		=	minishell.h msh_commands.h
HEAD_LINE_PRS	=	line_parser.h lp_commands.h

#-------------------------- Source files ---------------------------------------
C_MSH		= 	main.c msh_exit.c msh_free.c msh_execute_cmd.c\
				msh_utility.c msh_env_get.c

C_CMDS		=	msh_cd.c msh_echo.c msh_env.c msh_setenv.c msh_unsetenv.c

C_LP		=	line_parser.c lp_arg_buf_control.c lp_utility.c\
				lp_push_to_list.c

C_LP_CMD	=	lp_dollar.c lp_backslash.c lp_single_quotes.c lp_double_quotes.c\
				lp_space.c lp_semicolon.c

OBJ 		= 	$(addprefix $(DIR_OBJ), $(C_MSH:.c=.o) $(C_CMDS:.c=.o) \
				$(C_LP:.c=.o) $(C_LP_CMD:.c=.o))

INC 			= 	$(addprefix -I, $(DIR_INC) $(DIR_LIB_INC))
INC_BASE 		= 	$(addprefix $(DIR_INC), $(HEAD_BASE))
INC_LINE_PRS	= 	$(addprefix $(DIR_INC), $(HEAD_BASE) $(HEAD_LINE_PRS))


all: lib $(NAME)

lib:
	@make -C $(DIR_LIB)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(READLINE_FLAG) $(LIBFT) 
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(INC_BASE)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#msh_commands
$(DIR_OBJ)%.o: $(DIR_CMDS)%.c $(INC_BASE)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#line_parser
$(DIR_OBJ)%.o: $(DIR_LP)%.c $(INC_LINE_PRS)
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#lp_commands
$(DIR_OBJ)%.o: $(DIR_LP_CMD)%.c $(INC_LINE_PRS)
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
