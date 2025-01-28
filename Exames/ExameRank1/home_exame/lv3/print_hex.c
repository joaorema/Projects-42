#include <unistd.h>

void print_hex(int nb)
{
	char base[] = "0123456789abcdef";

	if(nb > 15)
	{
		print_hex(nb / 16);
	}
	write(1, &base[nb % 16], 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int r = 0;

	while(str[i])
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return r;
}

int main(int ac, char *av[])
{
	int nb;

	if(ac == 2)
	{
		nb = ft_atoi(av[1]);
		print_hex(nb);
	}
	write(1, "\n", 1);
	return 0;
}
