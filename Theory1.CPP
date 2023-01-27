#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/*int compare(char r[], char b[])
{
    int j = 0;
    int count = 0;
    int i = 0;
    while (r[i] != '\0')
    {
        if (r[i] == b[j] && r[i + 1] == b[j + 1])
        {
            count++;
        }
        i++;
    }
    return count;
}*/
int compare(char *r, char *b)
{
    int count = 0;
    while (*r != '\0')
    {
        if (*r == *b && *(r + 1) == *(b + 1))
        {
            count++;
        }
        *r++;
    }
    return count;
}
int main()
{
    char s1[] = "abcaabca";
    char s2[] = "ab";
    int result = compare(s1, s2);
    cout << s2 << " appears " << result << " times" << endl;
    return 0;
}