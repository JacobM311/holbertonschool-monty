#include "monty.h"
int main(int argc, char **argv)
{
    FILE *fp;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    oc = fopen(argv[1], "r");

    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file\n");
        exit(EXIT_FAILURE);
    }
}