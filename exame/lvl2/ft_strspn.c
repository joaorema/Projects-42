#include <stdlib.h>
#include <stdio.h>

char *ft_strchr(const char *str, char c)
{
	while(*str)
	{
		if(*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return 0;
}

size_t ft_strspn(const char *s, const char *accept)
{
	int len = 0;

	while(s[len])
	{
		if(ft_strchr(accept, s[len]) == 0)
		{
			break;
		}
		len++;
	}
	return len;
}

#include <stdio.h>

int main()
{
	char str[] = "ola , andas por aqui?";
	char c[] = "hola";
	int result = ft_strspn(str, c);
	printf("%d\n", result);
}

