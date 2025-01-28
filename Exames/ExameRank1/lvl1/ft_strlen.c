#include <unistd.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;

	while(str[i])
	{
		i++;
	}
	return i;
}

/*
#include <stdio.h>

int main()
{
	char teste[] = "grande";
	int len = ft_strlen(teste);
	printf("%d\n", len);

}
*/
