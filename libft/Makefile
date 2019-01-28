#-------------------------- Key Values -----------------------------------------
NAME		:=	libft.a
CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc

DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

LIB			:=	libc/
GNL			:=	get_next_line/
FPF			:=	printf/

DIR_LIB_INC	:=	$(DIR_INC)$(LIB)
DIR_GNL_INC	:=	$(DIR_INC)$(GNL)
DIR_FPF_INC	:=	$(DIR_INC)$(FPF)

DIR_LIB_SRC	:=	$(DIR_SRC)$(LIB)
DIR_GNL_SRC	:=	$(DIR_SRC)$(GNL)
DIR_FPF_SRC	:=	$(DIR_SRC)$(FPF)

DIR_MEM		:=	$(DIR_LIB_SRC)mem/
DIR_STR		:=	$(DIR_LIB_SRC)str/
DIR_IS		:=	$(DIR_LIB_SRC)is/
DIR_TO		:=	$(DIR_LIB_SRC)to/
DIR_PUT		:=	$(DIR_LIB_SRC)put/
DIR_LST		:=	$(DIR_LIB_SRC)lst/
DIR_ARR		:=	$(DIR_LIB_SRC)arr/
DIR_OTHER	:=	$(DIR_LIB_SRC)other/

#-------------------------- Header files ---------------------------------------
LIB_H		:=	$(DIR_LIB_INC)libft.h\
				$(DIR_LIB_INC)ft_def.h\
				$(DIR_LIB_INC)ft_mem.h\
				$(DIR_LIB_INC)ft_str.h\
				$(DIR_LIB_INC)ft_is.h\
				$(DIR_LIB_INC)ft_to.h\
				$(DIR_LIB_INC)ft_put.h\
				$(DIR_LIB_INC)ft_lst.h\
				$(DIR_LIB_INC)ft_arr.h\
				$(DIR_LIB_INC)ft_other.h

GNL_H		:=	$(DIR_GNL_INC)get_next_line.h

FPF_H		:=	$(DIR_FPF_INC)ft_printf.h

#-------------------------- Source files ---------------------------------------
LIB_C		:=	$(DIR_MEM)ft_bzero.c\
				$(DIR_MEM)ft_memalloc.c\
				$(DIR_MEM)ft_memccpy.c\
				$(DIR_MEM)ft_memchr.c\
				$(DIR_MEM)ft_memcmp.c\
				$(DIR_MEM)ft_memcpy.c\
				$(DIR_MEM)ft_memdel.c\
				$(DIR_MEM)ft_memmove.c\
				$(DIR_MEM)ft_memset.c\
				$(DIR_MEM)ft_memrev.c\
				$(DIR_MEM)ft_memjoin.c\
				$(DIR_MEM)ft_memjoin_free.c\
				$(DIR_STR)ft_strcat.c\
				$(DIR_STR)ft_strchr.c\
				$(DIR_STR)ft_strclr.c\
				$(DIR_STR)ft_strcmp.c\
				$(DIR_STR)ft_strcpy.c\
				$(DIR_STR)ft_strdup_free.c\
				$(DIR_STR)ft_strdel.c\
				$(DIR_STR)ft_strdup.c\
				$(DIR_STR)ft_strequ.c\
				$(DIR_STR)ft_striter.c\
				$(DIR_STR)ft_striteri.c\
				$(DIR_STR)ft_strjoin.c\
				$(DIR_STR)ft_strnjoin.c\
				$(DIR_STR)ft_strjoin_free.c\
				$(DIR_STR)ft_strlcat.c\
				$(DIR_STR)ft_strlen.c\
				$(DIR_STR)ft_strmap.c\
				$(DIR_STR)ft_strmapi.c\
				$(DIR_STR)ft_strncat.c\
				$(DIR_STR)ft_strncmp.c\
				$(DIR_STR)ft_strncpy.c\
				$(DIR_STR)ft_strnequ.c\
				$(DIR_STR)ft_strnew.c\
				$(DIR_STR)ft_strnstr.c\
				$(DIR_STR)ft_strrchr.c\
				$(DIR_STR)ft_strsplit.c\
				$(DIR_STR)ft_strstr.c\
				$(DIR_STR)ft_strsub.c\
				$(DIR_STR)ft_strtrim.c\
				$(DIR_IS)ft_isalnum.c\
				$(DIR_IS)ft_isalpha.c\
				$(DIR_IS)ft_isascii.c\
				$(DIR_IS)ft_isdigit.c\
				$(DIR_IS)ft_islower.c\
				$(DIR_IS)ft_isprint.c\
				$(DIR_IS)ft_isspace.c\
				$(DIR_IS)ft_is_str_alpha.c\
				$(DIR_IS)ft_is_str_digit.c\
				$(DIR_IS)ft_is_str_lower.c\
				$(DIR_IS)ft_is_str_upper.c\
				$(DIR_IS)ft_is_str_space.c\
				$(DIR_IS)ft_isupper.c\
				$(DIR_IS)ft_isalpha_in_case.c\
				$(DIR_IS)ft_isalnum_in_case.c\
				$(DIR_TO)ft_tolower.c\
				$(DIR_TO)ft_to_str_lower.c\
				$(DIR_TO)ft_to_str_upper.c\
				$(DIR_TO)ft_toupper.c\
				$(DIR_PUT)ft_putchar.c\
				$(DIR_PUT)ft_putchar_fd.c\
				$(DIR_PUT)ft_putendl.c\
				$(DIR_PUT)ft_putendl_fd.c\
				$(DIR_PUT)ft_putnbr.c\
				$(DIR_PUT)ft_putnbr_fd.c\
				$(DIR_PUT)ft_putstr.c\
				$(DIR_PUT)ft_putstr_fd.c\
				$(DIR_PUT)ft_putarr.c\
				$(DIR_PUT)ft_putarr_fd.c\
				$(DIR_LST)ft_lstadd.c\
				$(DIR_LST)ft_lstdel.c\
				$(DIR_LST)ft_lstdelone.c\
				$(DIR_LST)ft_lstiter.c\
				$(DIR_LST)ft_lstmap.c\
				$(DIR_LST)ft_lstnew.c\
				$(DIR_LST)ft_lstpop.c\
				$(DIR_LST)ft_lstrev.c\
				$(DIR_ARR)ft_arrdel.c\
				$(DIR_ARR)ft_arrlen.c\
				$(DIR_ARR)ft_arrnew.c\
				$(DIR_OTHER)ft_atoi.c\
				$(DIR_OTHER)ft_itoa.c\
				$(DIR_OTHER)ft_nbrlen.c\
				$(DIR_OTHER)ft_clear.c\
				$(DIR_OTHER)ft_perror_exit.c

GNL_C		:=	$(DIR_GNL_SRC)get_next_line.c

FPF_C		:=	$(DIR_FPF_SRC)ft_printf.c\
				$(DIR_FPF_SRC)fpf_cat_data.c\
				$(DIR_FPF_SRC)fpf_parser.c\
				$(DIR_FPF_SRC)fpf_trash.c\
				$(DIR_FPF_SRC)fpf_parser_get_type.c\
				$(DIR_FPF_SRC)fpf_conversions.c\
				$(DIR_FPF_SRC)fpf_unicode.c\
				$(DIR_FPF_SRC)fpf_output_sc.c\
				$(DIR_FPF_SRC)fpf_output_d.c\
				$(DIR_FPF_SRC)fpf_output_u.c\
				$(DIR_FPF_SRC)fpf_output_ox.c\
				$(DIR_FPF_SRC)fpf_output_p.c\
				$(DIR_FPF_SRC)fpf_colors.c\
				$(DIR_FPF_SRC)fpf_bonus_flags.c

#-------------------------- Init OBJ INC ---------------------------------------
OBJ			:=	$(patsubst $(DIR_LIB_SRC)%,$(DIR_OBJ)%,\
				$(LIB_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_GNL_SRC)%,$(DIR_OBJ)%,\
				$(GNL_C:.$(CH_SRC)=.$(CH_OBJ)))
OBJ			+=	$(patsubst $(DIR_FPF_SRC)%,$(DIR_OBJ)%,\
				$(FPF_C:.$(CH_SRC)=.$(CH_OBJ)))


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
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_LIB_SRC)%.$(CH_SRC)\
$(LIB_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#GNL
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_GNL_SRC)%.$(CH_SRC)\
$(LIB_H) $(GNL_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#FPF
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_FPF_SRC)%.$(CH_SRC)\
$(LIB_H) $(FPF_H)
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
