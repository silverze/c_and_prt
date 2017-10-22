#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general_config.h"

#define METHOD          1

#define FILE_MAX_LEN    100000
#define LINE_MAX_LEN    512

char stdin_file[FILENAME_MAX];

void read_stdin_file(char *file_str);//从标准输入中读取字符串

#if (METHOD == 1)
int cal_left_braces(char const *input); //计算左花括号{的个数
int cal_right_braces(char const *input); //计算右花括号{的个数
#else
bool check_c_program(char *file_str);
#endif

int main()
{
    #if (METHOD == 1)
    int left;
    int right;
    #endif

    read_stdin_file(stdin_file);

    #if (METHOD == 1)
    left = cal_left_braces(stdin_file);
    right = cal_right_braces(stdin_file);
    #endif

    #if (METHOD == 1)
    if (left == right)
    {
        puts("Check successed !");
    }
    else
    {
        puts("Check failed !");
    }
    #else
    if (check_c_program(stdin_file) == True)
    {
        puts("Check successed !");
    }
    else
    {
        puts("Check failed !");
    }
    #endif

    return 0;
}

/**
  * 从标准输入中读取字符串，当遇到两个回车则认为
  * 输入结束，退出该函数
  * @param file_str 存储从标准输入读取的字符串
  * @authr silver
  */
void read_stdin_file(char *file_str)
{
    char cur_line[LINE_MAX_LEN];
    while (gets(cur_line))
    {
        if (strlen(cur_line) > 0)
        {
            strcat(file_str, cur_line);
            strcat(file_str, "\n");
        }
        else
        {
            break;
        }
    }
}

#if (METHOD == 1)
/**
  * 查询字符串中'{'的个数
  * @param input 待查询的字符串
  * @authr silver
  */
int cal_left_braces(char const *input)
{
    int i = 0;
    int len = 0;
    int counter = 0;

    len = strlen(input);
    for (i = 0; i < len; i++)
    {
        if (input[i] == '{')
        {
            counter++;
        }
    }
    return counter;
}
#endif

#if (METHOD == 1)
/**
  * 查询字符串中'}'的个数
  * @param input 待查询的字符串
  * @authr silver
  */
int cal_right_braces(char const *input)
{
    int i = 0;
    int len = 0;
    int counter = 0;

    len = strlen(input);
    for (i = 0; i < len; i++)
    {
        if (input[i] == '}')
        {
            counter++;
        }
    }
    return counter;
}
#endif

#if (METHOD != 1)
/**
  * 检测字符串中 '{' 与 '}' 的个数是否相等
  * @param input 待检测的字符串
  * @return 相等为True，不等为False
  * @authr silver
  */
bool check_c_program(char *input)
{
    int i;
    int len;
    int left = 0;
    int right = 0;

    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == '{')
        {
            left++;
        }
        if (input[i] == '}')
        {
            right++;
        }
    }

    if(left == right)
    {
        return True;
    }
    else
    {
        return False;
    }
}
#endif
