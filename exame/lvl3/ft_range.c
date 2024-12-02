#include <stdlib.h>

int *ft_range(int start, int end)
{
	int i = 0;
	int len;
	int *res;
	
	len = abs((end - start)) + 1;
	res = (int *)malloc(sizeof(int) * len);
	if(res == NULL)
	{
		return NULL;
	}
	if(start < end)
	{
		while(i < len)
		{
			res[i++] = start++;
		}
	}
	else
	{
		while(i < len)
		{
			res[i++] = start--;
		}
	}
	return res;
}

#include <stdio.h>

int *ft_range(int start, int end);

int main(void)
{
    int start = 1;
    int end = 5;
    int *range = ft_range(start, end);

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
