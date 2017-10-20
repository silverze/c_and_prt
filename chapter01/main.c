#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general_config.h"

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrage(char *output, char const *input, int n_columns, int const columns[]);

bool bl = TRUE;

int main()
{
    int n_colums;
    int colums[MAX_COLS];
    char input[MAX_INPUT];

    n_colums = read_column_numbers(colums, MAX_COLS);

    while ( gets(input) != NULL)
    {
        printf("Original input : %s\n", input);
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == TRUE
           && columns[num] > 0)
    {
        num += 1;
    }

    if (num%2 != 0)
    {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }
    while ((ch = getchar()) != EOF && ch != '\n' )
    {
    }

    return num;
}
