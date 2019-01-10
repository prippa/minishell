#include "libft/includes/libft.h"

typedef struct	s_car
{
	char		*name;
}				t_car;

void print_car2(t_list2 *elem)
{
	t_car *car;

	car = (t_car *)elem->content;
	ft_printf("id = [%zd], speed = [%hu]\n", car->id, car->speed);
}

void print_car(t_list *elem)
{
	t_car *car;

	car = (t_car *)elem->content;
	ft_printf("id = [%zd], speed = [%hu]\n", car->id, car->speed);
}

void add_car(t_list *)

int main(int argc, char const *argv[])
{
	// t_list2 *start;
	// t_list2 *end;

	// ft_lst2_push_back(&start, &end, ft_lst2new(&(t_car){.id = 1, .speed = 180}, sizeof(t_car)));
	// ft_lst2_push_back(&start, &end, ft_lst2new(&(t_car){.id = 2, .speed = 100}, sizeof(t_car)));
	// ft_lst2_push_back(&start, &end, ft_lst2new(&(t_car){.id = 3, .speed = 220}, sizeof(t_car)));
	// ft_lst2iter(start, &print_car2);
	// ft_lst2rev(&start, &end);
	// ft_printf("\n");
	// ft_lst2iter(start, &print_car2);
	t_list *lst;
	size_t size = 0;

	ft_lstadd(&lst, ft_lstnew(&(t_car){.id = 1, .speed = 180}, sizeof(t_car)));
	ft_lstadd(&lst, ft_lstnew(&(t_car){.id = 2, .speed = 100}, sizeof(t_car)));
	ft_lstadd(&lst, ft_lstnew(&(t_car){.id = 3, .speed = 220}, sizeof(t_car)));
	ft_lstiter(lst, &print_car);
	ft_lstrev(&lst);
	ft_printf("\n");
	ft_lstiter(lst, &print_car);
	return 0;
}

