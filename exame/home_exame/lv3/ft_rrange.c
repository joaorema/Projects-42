#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int len = abs(end - start) + 1;
	int *new = (int *)malloc(sizeof(int) * len);
	int i = 0;

	while(i < len)
	{
		if(start < end)
		{
			new[i] = end;
			end--;
			i++;
		}
		else
		{
			new[i] = end;
			end++;
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
	int i = 0;
	int *new = ft_rrange(s, e);

	while(i < abs(e - s) + 1)
	{
		printf("%d\n", new[i]);
		i++;
	}
}
