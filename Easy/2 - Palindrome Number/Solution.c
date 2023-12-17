#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *ToString(long x, char *str);
bool isPalindrome(int x) 
{
    int i = 0;
    int j = 0;
    char *str = (char *)malloc(100 * sizeof(char));
    if (str == NULL)
        return false;
    str = ToString((long)x, str);
    while (str[i])
        i++;
    while (j < i / 2) 
    {
        if (str[j] != str[i - j - 1]) 
        {
            free(str);
            return false;
        }
        j++;
    }
    free(str);
    return true;
}

char *ToString(long x, char *str) 
{
    int i = 0;
    if (x < 0) 
    {
        x *= (-1);
        str[i] = '-';
        i++;
    }
    while (x > 0) 
    {
        if (x > 9) 
        {
            str[i] = (x % 10) + '0';
            x = x / 10;
            i++;
        }
        if (x <= 9) 
        {
            str[i] = x + '0';
            break;
        }
    }
    str[i + 1] = '\0';
    return str;
}

int main() {
    // Test cases
    int testCases[] = { 1221, -1221, 1234, 0 };
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; ++i) {
        printf("Number: %d\nPalindrome: %s\n\n", testCases[i], isPalindrome(testCases[i]) ? "true" : "false");
    }

    return 0;
}