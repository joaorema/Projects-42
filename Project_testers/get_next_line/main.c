#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char *line = NULL;
    int line_count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) 
    {
        perror("Error opening file");
        return 1;
    }
    printf("File opened successfully\n");

    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("Reading line: %s", line);
        free(line); // Free the allocated memory for the line
        line_count++;
    }

    close(fd);
    return 0;
}
