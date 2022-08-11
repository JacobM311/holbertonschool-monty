#include "monty.h"
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
        fprintf(stderr, "Error: Can't open file\n");
        exit(EXIT_FAILURE);
    }
}