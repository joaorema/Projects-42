#include <stdlib.h>
size_t  ft_strcspn(const char *s, const char *reject)
{
    int     i = 0;
    int     j = 0;

    while (s[i] != '\0')
    {
	j = 0;
        while (reject[j] != '\0')
        {
            if(s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

#include <stdio.h>

int main()
{
	char teste[] = "ola. isto vai ser um teste, acho eu";
	char r[] = "l";

	printf("%zu\n", ft_strcspn(teste, r));

}
