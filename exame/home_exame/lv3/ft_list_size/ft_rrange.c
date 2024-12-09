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
		{	new[i] = end;
			end++;
			i++;
		}
	}
	return new;
}

#include <stdio.h>

int main(void)
{
    int start = 0;
    int end = -5;
    int *range = ft_rrange(start, end);
    int i = 0;

    while(i <= abs(end - start))
    {
        printf("%i ", range[i]);
	i++;
    }
    printf("\n");

    free(range);
    return 0;
}
