void ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

/*
#include <stdio.h>

int main()
{
	int x = 5;
	int y = 10;

	printf("Before swap : x = %i, y = %i\n", x , y);

	ft_swap(&x, &y);

	printf("After swap : x = %i, y = %i\n", x , y);

	return 0;
}
*/
