#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	char teste[] = "ola";

	ft_putstr(teste);
	write(1, "\n", 1);
}
