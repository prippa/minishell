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

NAME		=	libft.a
FLAGS		= 	-Wall -Werror -Wextra
CC			=	gcc

DIR_LIBFT_I	=	includes/libc/
DIR_GNL_I	=	includes/get_next_line/
DIR_FPF_I	=	includes/printf/

DIR_INC		=	$(DIR_LIBFT_I) $(DIR_GNL_I) $(DIR_FPF_I)

DIR_SRC		=	source/
DIR_LIB		=	$(DIR_SRC)libc/

DIR_MEM		=	$(DIR_LIB)mem/
DIR_STR		=	$(DIR_LIB)str/
DIR_IS		=	$(DIR_LIB)is/
DIR_TO		=	$(DIR_LIB)to/
DIR_PUT		=	$(DIR_LIB)put/
DIR_LST		=	$(DIR_LIB)lst/
DIR_ARR		=	$(DIR_LIB)arr/
DIR_OTHER	=	$(DIR_LIB)other/
DIR_GNL		=	$(DIR_SRC)get_next_line/
DIR_FPF		=	$(DIR_SRC)printf/


HEAD		=	$(DIR_LIBFT_I)libft.h\
				$(DIR_LIBFT_I)ft_def.h\
				$(DIR_LIBFT_I)ft_mem.h\
				$(DIR_LIBFT_I)ft_str.h\
				$(DIR_LIBFT_I)ft_is.h\
				$(DIR_LIBFT_I)ft_to.h\
				$(DIR_LIBFT_I)ft_put.h\
				$(DIR_LIBFT_I)ft_lst.h\
				$(DIR_LIBFT_I)ft_arr.h\
				$(DIR_LIBFT_I)ft_other.h\
				$(DIR_GNL_I)get_next_line.h\
				$(DIR_FPF_I)ft_printf.h

LIB_C		=	$(DIR_MEM)ft_bzero.c\
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

GNL_C		=	$(DIR_GNL)get_next_line.c

FPF_C		=	$(DIR_FPF)ft_printf.c\
				$(DIR_FPF)fpf_cat_data.c\
				$(DIR_FPF)fpf_parser.c\
				$(DIR_FPF)fpf_trash.c\
				$(DIR_FPF)fpf_parser_get_type.c\
				$(DIR_FPF)fpf_conversions.c\
				$(DIR_FPF)fpf_unicode.c\
				$(DIR_FPF)fpf_output_sc.c\
				$(DIR_FPF)fpf_output_d.c\
				$(DIR_FPF)fpf_output_u.c\
				$(DIR_FPF)fpf_output_ox.c\
				$(DIR_FPF)fpf_output_p.c\
				$(DIR_FPF)fpf_colors.c\
				$(DIR_FPF)fpf_bonus_flags.c


OBJ 		=	$(LIB_C:.c=.o)
OBJ			+=	$(GNL_C:.c=.o)
OBJ			+=	$(FPF_C:.c=.o)

INC 		=	$(addprefix -I, $(DIR_INC))


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ]

$(OBJ): %.o: %.c $(HEAD)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ)
	@echo "Clean [ obj files libft ]"

fclean:
	@rm -rf $(OBJ)
	@echo "Clean [ obj files libft ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
