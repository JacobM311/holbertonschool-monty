#include "main.h"
int main(int argc, char **argv)
{
    FILE *oc;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    oc = fopen(argv[1], "r");

    if (!oc)
    {
        fprintf(stderr, "Error: Unable open file\n");
        exit(EXIT_FAILURE);
    }
}