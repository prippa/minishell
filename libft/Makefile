#-------------------------- Key Values -----------------------------------------
NAME		:=	libft.a
CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc

DIR_INC		:=	includes
DIR_SRC		:=	source
DIR_OBJ		:=	object
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

LIB			:=	libc
GNL			:=	get_next_line
FPF			:=	printf

#-------------------------- inc srs Paths --------------------------------------
DIR_LIB_INC	:=	$(DIR_INC)/$(LIB)
DIR_GNL_INC	:=	$(DIR_INC)/$(GNL)
DIR_FPF_INC	:=	$(DIR_INC)/$(FPF)

DIR_LIB_SRC	:=	$(DIR_SRC)/$(LIB)
DIR_GNL_SRC	:=	$(DIR_SRC)/$(GNL)
DIR_FPF_SRC	:=	$(DIR_SRC)/$(FPF)

#-------------------------- Init of Values -------------------------------------
LIB_HEAD	:=	$(shell find $(DIR_LIB_INC) -type f -name *.$(CH_HEAD))
GNL_HEAD	:=	$(shell find $(DIR_GNL_INC) -type f -name *.$(CH_HEAD))
FPF_HEAD	:=	$(shell find $(DIR_FPF_INC) -type f -name *.$(CH_HEAD))

LIB_SRC		:=	$(shell find $(DIR_LIB_SRC) -type f -name *.$(CH_SRC))
GNL_SRC		:=	$(shell find $(DIR_GNL_SRC) -type f -name *.$(CH_SRC))
FPF_SRC		:=	$(shell find $(DIR_FPF_SRC) -type f -name *.$(CH_SRC))

OBJ			:=	$(patsubst $(DIR_LIB_SRC)/%,$(DIR_OBJ)/%,\
				$(LIB_SRC:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_GNL_SRC)/%,$(DIR_OBJ)/%,\
				$(GNL_SRC:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_FPF_SRC)/%,$(DIR_OBJ)/%,\
				$(FPF_SRC:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_LIB_INC) $(DIR_GNL_INC) $(DIR_FPF_INC))

#-------------------------- Make -----------------------------------------------
all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Linking" [ $(NAME) ]

#-------------------------- Compil Block ---------------------------------------
#LIB
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_LIB_SRC)/%.$(CH_SRC)\
$(LIB_HEAD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#GNL
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_GNL_SRC)/%.$(CH_SRC)\
$(LIB_HEAD) $(GNL_HEAD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#FPF
$(DIR_OBJ)/%.$(CH_OBJ): $(DIR_FPF_SRC)/%.$(CH_SRC)\
$(LIB_HEAD) $(FPF_HEAD)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#-------------------------- Clean ----------------------------------------------
clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
