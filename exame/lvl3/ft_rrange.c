#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int step = 1;
	int len;

	len = abs(end - start) + 1;
	range = (int *)malloc(sizeof(int) * len);
	if(range)
	{
		if(start < end)
		{
			step = -1;
		}
		while(i < len)
		{
			range[i] = end;
			end = end + step;
			i++;
		}
	}
	return range;
}

#include <stdio.h>

int *ft_rrange(int start, int end);

int main(void)
{
    int start = 1;
    int end = 5;
    int *range = ft_rrange(start, end);

    if (range != NULL)
    {
        for (int i = 0; i <= abs(end - start); i++)
        {
            printf("%i ", range[i]);
        }
        printf("\n");
        free(range);
    }

    return 0;
}

