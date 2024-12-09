#include <stddef.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;

	while(*s1)
	{
		i = 0;
		while(s2[i])
		{
			if(*s1 == s2[i])
			{
				return (char *) s1;
			}
			i++;
		}
		s1++;
	}
	return NULL;
}
#include  <stdio.h>

int main()
{
	char *str = "teste idiota teste";
	char *s = "t";

	printf("%s\n", ft_strpbrk(str, s));
}
