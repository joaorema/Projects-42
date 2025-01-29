#include "get_next_line.h"

static char *append_char(char *str, char c, int len)
{
    char *new_str;
    int i;

    new_str = (char *)malloc(len + 2); // +1 for new char, +1 for '\0'
    if (!new_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i++] = c;
    new_str[i] = '\0';
    free(str);
    return (new_str);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buf_index = 0;
    static int buf_size = 0;
    char *line = NULL;
    int i = 0;

    if (BUFFER_SIZE < 1 || fd < 0)
        return (NULL);
    
    line = (char *)malloc(1);
    if (!line)
        return (NULL);
    line[0] = '\0';

    while (1)
    {
        if (buf_index >= buf_size)
        {
            buf_size = read(fd, buffer, BUFFER_SIZE);
            buf_index = 0;
            if (buf_size <= 0)
            {
                if (i == 0)
                {
                    free(line);
                    return (NULL);
                }
                break;
            }
        }
        line = append_char(line, buffer[buf_index++], i);
        if (!line)
            return (NULL);
        if (line[i++] == '\n')
            break;
    }
    return (line);
}
/*
int main(void)
{
    int     fd;
    char    *str;
    char    *path;
    int     line;

    path = "test.txt";
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    line = 1;
    while ((str = get_next_line(fd)))
    {
        printf("Linha: %i\n", line);
        printf("%s\n", str); 
        free(str); 
        line++;
    }
    close(fd); 
    return (0);
}
*/
