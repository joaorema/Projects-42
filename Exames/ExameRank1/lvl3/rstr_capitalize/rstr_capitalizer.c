#include <unistd.h>

void rstr_capitalizer(char *str)
{
	int i = 0;
	int last;

	while(str[i])
	{
		last = str[i + 1];
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		if((str[i] >= 'a' && str[i] <= 'z') && (last == ' ' || last == '\t' || last == '\0'))
		{
			str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i;

	if(argc > 1)
	{
		i = 1;
		while(i < argc)
		{
			rstr_capitalizer(argv[1]);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
