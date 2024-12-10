void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp;

	while(i < (size - 1))
	{
		if(tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

#include <stdio.h>
int main()
{
	unsigned int s = 10;
	int tab[] = {5, 2, 7, 1, 15, 1, 19, 4, 3, 20};
	sort_int_tab(tab, s);
	int i = 0;

	while(i < 10)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
