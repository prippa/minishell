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

#-------------------------- Key Values -----------------------------------------
NAME		:=	minishell
CFLAGS		:=	-Wall -Werror -Wextra
READLINE_F	:=	-lreadline
CC			:=	gcc

DIR_LIB		:=	libft
DIR_INC		:=	includes
DIR_SRC		:=	source
DIR_OBJ		:=	object
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

COR			:=	core
LNL			:=	line_lexer
LNP			:=	line_parser

LIBFT		:=	$(DIR_LIB)/libft.a

#-------------------------- inc srs Paths --------------------------------------
DIR_COR_INC	:=	$(DIR_INC)/$(COR)
DIR_LNL_INC	:=	$(DIR_INC)/$(LNL)
DIR_LNP_INC	:=	$(DIR_INC)/$(LNP)

DIR_COR_SRC	:=	$(DIR_SRC)/$(COR)
DIR_LNL_SRC	:=	$(DIR_SRC)/$(LNL)
DIR_LNP_SRC	:=	$(DIR_SRC)/$(LNP)

#-------------------------- Init of Values -------------------------------------
COR_HEAD	:=	$(shell find $(DIR_COR_INC) -type f -name *.$(CH_HEAD))
LNL_HEAD	:=	$(shell find $(DIR_LNL_INC) -type f -name *.$(CH_HEAD))
LNP_HEAD	:=	$(shell find $(DIR_LNP_INC) -type f -name *.$(CH_HEAD))

COR_SRC		:=	$(shell find $(DIR_COR_SRC) -type f -name *.$(CH_SRC))
LNL_SRC		:=	$(shell find $(DIR_LNL_SRC) -type f -name *.$(CH_SRC))
LNP_SRC		:=	$(shell find $(DIR_LNP_SRC) -type f -name *.$(CH_SRC))

OBJ			:=	$(patsubst $(DIR_COR_SRC)/%,$(DIR_OBJ)/%,\
				$(COR_SRC:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNL_SRC)/%,$(DIR_OBJ)/%,\
				$(LNL_SRC:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_LNP_SRC)/%,$(DIR_OBJ)/%,\
				$(LNP_SRC:.$(CH_SRC)=.$(CH_OBJ)))

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
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_COR_SRC)/%.$(CH_SRC)\
$(COR_HEAD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNL
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_LNL_SRC)/%.$(CH_SRC)\
$(COR_HEAD) $(LNL_HEAD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#LNP
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_LNP_SRC)/%.$(CH_SRC)\
$(COR_HEAD) $(LNP_HEAD)
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
