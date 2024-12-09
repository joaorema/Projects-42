int ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while(s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>

int main()
{
	char *str1 = "ola";
	char *str2 = "olb";

	printf("%d\n", ft_strcmp(str1, str2));
}
			

