#include <stdlib.h>

int count_words(char *str)
{
	int i = 0;
	int words = 0;

	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			i++;
		}
		if(str[i])
		{
			words++;
		}
		while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			i++;
		}
	}
	return words;
}

char *copy(char *new, char *old, int len)
{
	int i = 0;

	while(i < len && old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
	return new;
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int words = 0;
	char **new;

	words = count_words(str);
	new = (char **)malloc(sizeof(char *) * (words + 1));

	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			i++;
		}
		j = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		{
			i++;
		}
		if(i > j)
		{
			new[n] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			copy(new[n++], &str[j], i - j);
		}
	}
	new[n] = NULL;
	return new;
}

#include <stdio.h>

int main(int ac, char *av[])
{
	char **new;
	int i = 0;

	if(ac == 2)
	{
		new = ft_split(av[1]);
		while(new[i])
		{
			printf("%s\n", new[i++]);
		}
		free(new);
	}
}

