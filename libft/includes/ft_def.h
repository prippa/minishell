#ifndef FT_DEF_H
# define FT_DEF_H

# define ERR			-1
# define MALLOC_ERR		"malloc failed"
# define OPEN_ERR		"open failed"
# define READ_ERR		"read failed"
# define OTHER_ERR		"some system critical error happened"

typedef char	t_bool;
enum			{ false, true };

# define ABS(x) (((x) < 0) ? -(x) : (x))

# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

# define SWITCH_LOGIC(x) ((x) ? 0 : 1)

#endif
