#include <unistd.h>

char *rev_print(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		i++;
	}
	while(--i >= 0)
	{
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
	return(str);
}

/*
int main(void)
{
  rev_print("dlrow olleh");
  write (1, "\n", 1);
  rev_print("tnirp esreveR");
  write (1, "\n", 1);
}
*/
