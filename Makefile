#-------------------------- Key Values -----------------------------------------
NAME		:=	minishell
CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc -g

DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_SRC		:=	c
CH_OBJ		:=	o

COR			:=	core/
LNP			:=	line_parser/
RL			:=	read_line/
ENV			:=	environ_manipulation/

DIR_LIB		:=	libft/
DIR_LIB_INC	:=	$(DIR_LIB)includes/libc/ $(DIR_LIB)includes/printf/\
				$(DIR_LIB)includes/get_next_line/
LIBFT		:=	$(DIR_LIB)libft.a

DIR_COR_INC	:=	$(DIR_INC)$(COR)
DIR_LNP_INC	:=	$(DIR_INC)$(LNP)
DIR_RL_INC	:=	$(DIR_INC)$(RL)
DIR_ENV_INC	:=	$(DIR_INC)$(ENV)

DIR_COR_SRC	:=	$(DIR_SRC)$(COR)
DIR_LNP_SRC	:=	$(DIR_SRC)$(LNP)
DIR_RL_SRC	:=	$(DIR_SRC)$(RL)
DIR_ENV_SRC	:=	$(DIR_SRC)$(ENV)

DIR_BLT		:=	$(DIR_COR_SRC)builtin/
DIR_EXC		:=	$(DIR_COR_SRC)exec/
DIR_HLP		:=	$(DIR_COR_SRC)helpers/
DIR_INI		:=	$(DIR_COR_SRC)init/
DIR_LPCMD	:=	$(DIR_LNP_SRC)lp_commands/
DIR_LS		:=	$(DIR_RL_SRC)line_syntax/

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_COR_INC)shell.h\
				$(DIR_COR_INC)syntax_characters.h\
				$(DIR_COR_INC)builtin_static_arr.h\
				$(DIR_COR_INC)builtin.h\
				$(DIR_COR_INC)messages.h

ENV_H		:=	$(DIR_ENV_INC)environ_manipulation.h

LNP_H		:=	$(DIR_LNP_INC)line_parser.h

RL_H		:=	$(DIR_RL_INC)read_line.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_COR_SRC)main.c\
				$(DIR_INI)sh_init.c\
				$(DIR_INI)sh_init_env.c\
				$(DIR_BLT)sh_cd.c\
				$(DIR_BLT)sh_exit.c\
				$(DIR_BLT)sh_echo.c\
				$(DIR_BLT)sh_env.c\
				$(DIR_BLT)sh_setenv.c\
				$(DIR_BLT)sh_unsetenv.c\
				$(DIR_EXC)sh_exec.c\
				$(DIR_EXC)sh_process_cmd.c\
				$(DIR_HLP)sh_check_path_permision.c\
				$(DIR_HLP)sh_utility.c

ENV_C		:=	$(DIR_ENV_SRC)env_convert.c\
				$(DIR_ENV_SRC)env_free.c\
				$(DIR_ENV_SRC)env_get.c\
				$(DIR_ENV_SRC)env_print.c\
				$(DIR_ENV_SRC)env_set.c\
				$(DIR_ENV_SRC)env_unset.c\
				$(DIR_ENV_SRC)env_make_clone.c

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

RL_C		:=	$(DIR_RL_SRC)read_line.c\
				$(DIR_LS)rl_line_syntax.c\
				$(DIR_LS)rl_ls_commands.c

#-------------------------- Init OBJ, INC --------------------------------------
OBJ			:=	$(patsubst $(DIR_COR_SRC)%,$(DIR_OBJ)%,\
				$(COR_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNP_SRC)%,$(DIR_OBJ)%,\
				$(LNP_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_RL_SRC)%,$(DIR_OBJ)%,\
				$(RL_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_ENV_SRC)%,$(DIR_OBJ)%,\
				$(ENV_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_LIB_INC) $(DIR_COR_INC) $(DIR_LNP_INC)\
				$(DIR_RL_INC) $(DIR_ENV_INC))

#-------------------------- Make -----------------------------------------------
all: $(LIBFT) $(DIR_OBJ) $(NAME)

$(LIBFT):
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

#ENV
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_ENV_SRC)%.$(CH_SRC)\
$(ENV_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNP
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LNP_SRC)%.$(CH_SRC)\
$(COR_H) $(LNP_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#RL
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_RL_SRC)%.$(CH_SRC)\
$(COR_H) $(RL_H)
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
