#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *new;

	while(src[len])
	{
		len++;
	}
	new = malloc(sizeof(char) * (len + 1));
        while(src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

#include <stdio.h>

int main(int ac, char *av[])
{
	if(ac == 2)
	{
		printf("%s\n", ft_strdup(av[1]));
	}
}

