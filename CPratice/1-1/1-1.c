#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20  //所能处理的最大列号
#define MAX_INPUT 1000 //每个输入行的最大长度


int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void)
{
    int n_columns; //进行处理的列标号
    int columns[MAX_COLS]; //需要处理的列数
    char input[MAX_INPUT]; //容纳输入行的数组
    char output[MAX_INPUT]; //容纳输出行的数组

    //读取该串列的标号
    n_columns = read_column_numbers(columns, MAX_COLS);

    //读取、处理和打印剩于的输入行

    while (gets(input) != NULL)
    {
        printf("Original input : %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
    
}

/*
** 读取列标号，如果超出规定范围则不予理会 
*/

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
    {
       
        // printf("%d", columns[num]);
        num += 1;
    }

    // printf("%d",num);

    if(num%2 != 0)
    {
        puts("Last column number is not paired");
        exit(EXIT_FAILURE);
    }
    
    while ((ch = getchar()) != EOF && ch !='\n')
        ;
    return num;
    
}

void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;


    for ( col = 0; col < n_columns; col+=2)
    {
        printf("%d",columns[col]);
        int nchars = columns[col+1] - columns[col] + 1;

        if( columns[col] >= len || output_col == MAX_INPUT -1)
            break;
        
        if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT -output_col -1;
        strncpy(output + output_col, input + columns[col], nchars);
        output_col +=nchars;
    }
    output[output_col] = '\0';
    // printf("%s",output);
}