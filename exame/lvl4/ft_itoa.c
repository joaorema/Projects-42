#include <stdlib.h>

int sign(int nb)
{
	if(nb < 0)
	{
		return (-nb);
	}
	return nb;
}

int size(int nb)
{
	int i = 0;
	if(nb == 0)
	{
		return 1;
	}
	while(nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return i;
}

char *ft_itoa(int nbr)
{
	int len;
	int i = 0;
	char *new;

	len = size(nbr);
	if(nbr < 0)
	{
		i++;
	}
	len = len + i;
	new = (char *)malloc(sizeof(char) * (len + 1));
	new[0] = '-';
	new[len] = '\0';
	while(i <= (len - 1))
	{
		new[len - 1] = sign(nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return new;
}

#include <stdio.h>
int main()
{
	int nbr = -505;
	char *new = ft_itoa(nbr);
	int i = 0;

	while(new[i])
	{
		printf("%c", new[i]);
		i++;
	}
	printf("\n");
}
