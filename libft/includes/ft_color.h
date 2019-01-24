#ifndef FT_COLOR_H
# define FT_COLOR_H

# define COLOR_RESET	"\x1B[0m"
# define RED			"\x1B[31m"
# define YELLOW 		"\x1B[33m"
# define GREEN			"\x1B[32m"
# define CYAN			"\x1B[36m"
# define BLUE			"\x1B[34m"
# define MAGENTA		"\x1B[35m"
# define WHITE			"\x1B[37m"
# define GRAY			"\e[90m"

# define BOLD_GRAY		"\033[1;30m"
# define BOLD_RED		"\033[1;31m"
# define BOLD_GREEN		"\033[1;32m"
# define BOLD_YELLOW	"\033[1;33m"
# define BOLD_BLUE		"\033[1;34m"
# define BOLD_MAGENTA	"\033[1;35m"
# define BOLD_CYAN		"\033[1;36m"
# define BOLD_WHITE		"\033[1;39m"

# define BACK_RED_BLACK		"\e[30;41m"
# define BACK_GREEN_BLACK	"\e[30;42m"
# define BACK_BLUE_BLACK	"\e[30;44m"
# define BACK_CYAN_BLACK	"\e[30;46m"
# define BACK_GRAY_BLACK	"\e[30;100m"

# define BACK_RED_WHITE		"\e[1;97;41m"
# define BACK_GREEN_WHITE	"\e[1;97;42m"
# define BACK_BLUE_WHITE	"\e[1;97;44m"
# define BACK_CYAN_WHITE	"\e[1;97;46m"

typedef enum		e_fpf_colors
{
	F_GREEN = 1,
	F_BLUE,
	F_RED,
	F_CYAN,
	F_BOLD_GREEN,
	F_BOLD_BLUE,
	F_BOLD_RED,
	F_BOLD_CYAN,
	F_YELLOW,
	F_MAGENTA,
	F_WHITE,
	F_GRAY,
	F_BOLD_GRAY,
	F_BOLD_YELLOW,
	F_BOLD_MAGENTA,
	F_BOLD_WHITE,
	F_BACK_GREEN_BLACK,
	F_BACK_BLUE_BLACK,
	F_BACK_RED_BLACK,
	F_BACK_CYAN_BLACK,
	F_BACK_GRAY_BLACK,
	F_BACK_GREEN_WHITE,
	F_BACK_BLUE_WHITE,
	F_BACK_RED_WHITE,
	F_BACK_CYAN_WHITE
}					t_fpf_colors;

#endif
