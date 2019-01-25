#-------------------------- Key Values -----------------------------------------
NAME		:=	minishell
CFLAGS		:=	-Wall -Werror -Wextra
READLINE_F	:=	-lreadline
CC			:=	gcc

DIR_LIB		:=	libft/
DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

COR			:=	core/
LNL			:=	line_lexer/
LNP			:=	line_parser/

LIBFT		:=	$(DIR_LIB)libft.a

DIR_COR_INC	:=	$(DIR_INC)$(COR)
DIR_LNL_INC	:=	$(DIR_INC)$(LNL)
DIR_LNP_INC	:=	$(DIR_INC)$(LNP)

DIR_COR_SRC	:=	$(DIR_SRC)$(COR)
DIR_LNL_SRC	:=	$(DIR_SRC)$(LNL)
DIR_LNP_SRC	:=	$(DIR_SRC)$(LNP)

DIR_BLT		:=	$(DIR_COR_SRC)builtin/
DIR_LPCMD	:=	$(DIR_LNP_SRC)lp_commands/

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_COR_INC)minishell.h\
				$(DIR_COR_INC)syntax_characters.h

LNL_H		:=	$(DIR_LNL_INC)line_lexer.h

LNP_H		:=	$(DIR_LNP_INC)line_parser.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_COR_SRC)main.c\
				$(DIR_COR_SRC)msh_exit.c\
				$(DIR_COR_SRC)msh_free.c\
				$(DIR_COR_SRC)msh_execute_cmd.c\
				$(DIR_COR_SRC)msh_utility.c\
				$(DIR_COR_SRC)msh_env_get.c\
				$(DIR_COR_SRC)msh_search_command.c\
				$(DIR_COR_SRC)msh_fork_and_exec.c\
				$(DIR_BLT)msh_cd.c\
				$(DIR_BLT)msh_echo.c\
				$(DIR_BLT)msh_env.c\
				$(DIR_BLT)msh_setenv.c\
				$(DIR_BLT)msh_unsetenv.c


LNL_C		:=	$(DIR_LNL_SRC)line_lexer.c\
				$(DIR_LNL_SRC)lx_read_new_line.c\
				$(DIR_LNL_SRC)lx_commands.c

LNP_C		:=	$(DIR_LNP_SRC)line_parser.c\
				$(DIR_LNP_SRC)lp_arg_buf_control.c\
				$(DIR_LNP_SRC)lp_utility.c\
				$(DIR_LNP_SRC)lp_push_to_list.c\
				$(DIR_LPCMD)lp_dollar.c\
				$(DIR_LPCMD)lp_backslash.c\
				$(DIR_LPCMD)lp_single_quotes.c\
				$(DIR_LPCMD)lp_double_quotes.c\
				$(DIR_LPCMD)lp_space.c\
				$(DIR_LPCMD)lp_semicolon.c\
				$(DIR_LPCMD)lp_tilde.c


#-------------------------- Init OBJ INC ---------------------------------------
OBJ			:=	$(patsubst $(DIR_COR_SRC)%,$(DIR_OBJ)%,\
				$(COR_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNL_SRC)%,$(DIR_OBJ)%,\
				$(LNL_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNP_SRC)%,$(DIR_OBJ)%,\
				$(LNP_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_COR_INC) $(DIR_LNL_INC) $(DIR_LNP_INC))

#-------------------------- Make -----------------------------------------------
all: lib $(DIR_OBJ) $(NAME)

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(READLINE_F) $(LIBFT) 
	@echo "Linking" [ $(NAME) ]

#-------------------------- Compil Block ---------------------------------------
#COR
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_COR_SRC)%.$(CH_SRC)\
$(COR_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNL
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LNL_SRC)%.$(CH_SRC)\
$(COR_H) $(LNL_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNP
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LNP_SRC)%.$(CH_SRC)\
$(COR_H) $(LNP_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#-------------------------- Clean ----------------------------------------------
clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
