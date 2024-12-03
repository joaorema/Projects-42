#include <unistd.h>

void str_capitalizer(char *str)
{
	int i = 0;
	int first;

	if(str[i] >= 'a' && str[i] <= 'z')
	{
		str[i] = str[i] - 32;
	}
	write(1, &str[i], 1);
	while(str[i++])
	{
		first = str[i - 1];
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		if((str[i] >= 'a' && str[i] <= 'z') && (first == ' ' || first == '\t'))
		{
			str[i] = str[i] - 32;
		}
		write(1, &str[i], 1);
	}
}

int main(int argc, char *argv[])
{
        int i;

        if(argc > 1)
        {
                i = 1;
                while( i < argc)
                {
                        str_capitalizer(argv[1]);
                        write(1, "\n", 1);
                        i++;
                }
        }
        write(1, "\n", 1);
        return 0;
}

