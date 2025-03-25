#include <stdio.h>
#include <stdbool.h>

void read_line_end() { // TODO: you don't read "line end", you read to it, sorry my bad
    while (getchar() != '\n') {
        continue;       
    }
}
