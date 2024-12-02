#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
	int counter;

	if(!begin_list)
	{
		return 0;
	}
	counter = 0;
	while(begin_list)
	{
		++counter;
		begin_list = begin_list->next;
	}
	return counter;
}

#include <stdio.h>

int main(void)
{
    t_list node4 = {NULL, NULL};	
    t_list node3 = {&node4, NULL};
    t_list node2 = {&node3, NULL};
    t_list node1 = {&node2, NULL};

    int size = ft_list_size(&node1);
    printf("List size: %i\n", size);

    return 0;
}
