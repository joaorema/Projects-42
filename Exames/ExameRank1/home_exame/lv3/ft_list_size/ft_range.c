#include <stdlib.h>

int *ft_range(int start, int end)
{
	int len = abs(end - start) + 1;
	int *new =(int *)malloc(sizeof(int) * len);
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

int main()
{
	int start = 0;
	int end = 5;

	0,1,2,3,4,5
