#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if(nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if(nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
}

int main(int ac, char *av[])
{
	(void)av;
	if(ac < 2)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
	}
	if(ac > 1)
	{
		ft_putnbr(ac - 1);
		write(1, "\n", 1);
	}
}
