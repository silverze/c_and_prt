#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general_config.h"

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void segment(char *output, char const *input, int n_columns, int const columns[]);

bool bl = TRUE;

int main()
{
    int n_colums;
    int colums[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_colums = read_column_numbers(colums, MAX_COLS);

    printf("please input original string : ");
    while ( gets(input) != NULL )
    {
        printf("Original input : %s\n", input);
        segment(output, input, n_colums, colums);
        printf("Segment output : %s\n", output);
        printf("please input original string : ");
    }

    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    printf("please input you want select this string segment, like this: 1 3 5 8 -1\n");

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

void segment(char *output, char const *input, int n_columns, int const columns[])
{
    int i, j, k = 0;
    int start = 0;
    int end = 0;
    int input_len = strlen(input);

    if (input_len <= 0)
    {
        output[k] = '\0';
        return;
    }

    for (i = 0; i < columns[i]; i+=2)
    {
        start = columns[i];
        end = columns[i+1];

        if (start >= input_len && end > input_len)
        {
            break;
        }
        else
        {
           for (j = start; j <= end; j++)
            {
                output[k++] = input[j];
            }
        }
        output[k++] = ' ';
    }
    output[k] = '\0';
}
