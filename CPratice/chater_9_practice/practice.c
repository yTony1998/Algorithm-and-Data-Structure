#include <stdlib.h>
#include <string.h>
int main()
{
    char *ptr = NULL;
    int len1,len2;
    char  buffer[]= "25,412,330,Smith,J,239-4123";

    // C 库函数 size_t strspn(const char *str1, const char *str2) 检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标。
    len1 = strspn(buffer, "0123456789");
    len2 = strspn(buffer, ",0123456789");
    ptr = buffer + strspn(buffer,"\n\r\f\v");

    printf("%c\n",*ptr);
    printf("%d\n",len1);
    printf("%d\n",len2);


// C 库函数 size_t strcspn(const char *str1, const char *str2) 检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符。
    int len;
    const char str1[] = "ABCDEF4960910";
    const char str2[] = "013";

    len = strcspn(str1, str2);

    printf("第一个匹配的字符是在 %d\n", len + 1);
}