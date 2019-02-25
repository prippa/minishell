#-------------------------- Key Values -----------------------------------------
NAME		:=	minishell
CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc

DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

COR			:=	core/
LNS			:=	line_syntax/
LNP			:=	line_parser/

DIR_LIB		:=	libft/
DIR_LIB_INC	:=	$(DIR_LIB)includes/libc/ $(DIR_LIB)includes/printf/\
				$(DIR_LIB)includes/get_next_line/
LIBFT		:=	$(DIR_LIB)libft.a

DIR_COR_INC	:=	$(DIR_INC)$(COR)
DIR_LNS_INC	:=	$(DIR_INC)$(LNS)
DIR_LNP_INC	:=	$(DIR_INC)$(LNP)

DIR_COR_SRC	:=	$(DIR_SRC)$(COR)
DIR_LNS_SRC	:=	$(DIR_SRC)$(LNS)
DIR_LNP_SRC	:=	$(DIR_SRC)$(LNP)

DIR_BLT		:=	$(DIR_COR_SRC)builtin/
DIR_EXC		:=	$(DIR_COR_SRC)exec/
DIR_HLP		:=	$(DIR_COR_SRC)helpers/
DIR_INI		:=	$(DIR_COR_SRC)init/
DIR_LPCMD	:=	$(DIR_LNP_SRC)lp_commands/

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_COR_INC)minishell.h\
				$(DIR_COR_INC)syntax_characters.h\
				$(DIR_COR_INC)builtin_static_arr.h\
				$(DIR_COR_INC)builtin.h\
				$(DIR_COR_INC)messages.h

LNS_H		:=	$(DIR_LNS_INC)line_syntax.h

LNP_H		:=	$(DIR_LNP_INC)line_parser.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_COR_SRC)main.c\
				$(DIR_INI)msh_init.c\
				$(DIR_INI)msh_init_env.c\
				$(DIR_BLT)msh_cd.c\
				$(DIR_BLT)msh_exit.c\
				$(DIR_BLT)msh_echo.c\
				$(DIR_BLT)msh_env.c\
				$(DIR_BLT)msh_setenv.c\
				$(DIR_BLT)msh_unsetenv.c\
				$(DIR_EXC)msh_exec.c\
				$(DIR_EXC)msh_process_cmd.c\
				$(DIR_HLP)msh_free.c\
				$(DIR_HLP)msh_check_path_permision.c\
				$(DIR_HLP)msh_getenv.c\
				$(DIR_HLP)msh_utility.c


LNS_C		:=	$(DIR_LNS_SRC)line_syntax.c\
				$(DIR_LNS_SRC)ls_read_new_line.c\
				$(DIR_LNS_SRC)ls_commands.c

LNP_C		:=	$(DIR_LNP_SRC)line_parser.c\
				$(DIR_LNP_SRC)lp_arg_buf_control.c\
				$(DIR_LNP_SRC)lp_push.c\
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
OBJ			+=	$(patsubst $(DIR_LNS_SRC)%,$(DIR_OBJ)%,\
				$(LNS_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNP_SRC)%,$(DIR_OBJ)%,\
				$(LNP_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_LIB_INC) $(DIR_COR_INC) $(DIR_LNS_INC)\
				$(DIR_LNP_INC))

#-------------------------- Make -----------------------------------------------
all: lib $(DIR_OBJ) $(NAME)

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) 
	@echo "Linking" [ $(NAME) ]

#-------------------------- Compil Block ---------------------------------------
#COR
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_COR_SRC)%.$(CH_SRC)\
$(COR_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNS
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LNS_SRC)%.$(CH_SRC)\
$(COR_H) $(LNS_H)
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
