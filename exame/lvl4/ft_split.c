#include <stdlib.h>

int count_words(char *str)
{
	int i = 0;
	int count = 0;

	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t'))
		{
			i++;
		}
		if(str[i])
		{
			count++;
		}
		while(str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			i++;
		}
	}
	return count;
}

char *copy(char *new, char *old, int size)
{
	int i = 0;

	if(size == 0)
	{
		return 0;
	}
	while(i < size && old[i])
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
	char **new;
	int wc = 0;


	wc = count_words(str);
	new = (char **)malloc(sizeof(char *) * (wc + 1));
	
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t'))
                {
                        i++;
                }
		j = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\t'))
                {
                        i++;
                }
		if(i > j)
		{
			new[n] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			copy( new[n++], &str[j], i - j);

		}
		new[n] = NULL;
	}
	return new;
}

#include <stdio.h>

int main()
{
	char *teste = "ola isto vai ser um teste";
	char **new = ft_split(teste);
	int i = 0;

	while(new[i])
	{
		printf("%s\n", new[i]);
		i++;
	}
}
	

	
