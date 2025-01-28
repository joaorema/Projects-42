#include <stdlib.h>

int *ft_range(int start, int end)
{
	int len = abs(end - start) + 1;
	int *new = (int *)malloc(sizeof(int) * len);
	int i = 0;

	while(i < len)
	{
		if(start < end)
		{
			new[i] = start;
			start++;
			i++;
		}
		else
		{
			new[i] = start;
			start--;
			i++;
		}
	}
	return new;
}

#include <stdio.h>
int main()
{
	int s = 0;
	int e = -3;
	int *new = ft_range(s, e);
	int i = 0;

	while(i < abs(e - s) + 1)
	{
		printf("%d\n", new[i]);
		i++;
	}
}

	
