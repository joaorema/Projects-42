#include <unistd.h>

int ft_atoi(char *str)
{
	int r = 0;

	while(*str)
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return r;
}

void print_hex(int nb)
{
	char digit[] = "0123456789abcdef";

	if(nb >= 16)
	{
		print_hex(nb / 16);
	}
	write(1, &digit[nb % 16], 1);
}

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
	return 0;
}
