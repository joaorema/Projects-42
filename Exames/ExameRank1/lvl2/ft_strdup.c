#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *copy;

	while(src[len])
	{
		len++;
	}
	copy = malloc(sizeof(*copy) * (len + 1));
	if(copy != NULL)
	{
		while(src[i])
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
	}
	return copy;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%s\n", ft_strdup(argv[1]));
	}
}
