#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (strsSize == 0)
    {
        char *empty = (char *)malloc(sizeof(char));
        empty[0] = '\0';
        return (empty);
    }
    int prefixLen = 0;
    while(strs[0][prefixLen])
    {
        char currentChar = strs[0][prefixLen];
        for (int i = 1; i < strsSize; i++)
        {
            if (strs[i][prefixLen] != currentChar || strs[i][prefixLen] == '\0')
            {
                char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
                strncpy(result, strs[0], prefixLen);
                result[prefixLen] = '\0';
                return (result);
            }
        }
        prefixLen++;
    }
    char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return (result);
}

int main() 
{
    char* testCase1[] = {"flower", "flow", "flight"};
    int size1 = 3;
    char* result1 = longestCommonPrefix(testCase1, size1);
    printf("Test Case 1: Result = %s\n", result1);
    free(result1);

    char* testCase2[] = {};
    int size2 = 0;
    char* result2 = longestCommonPrefix(testCase2, size2);
    printf("Test Case 2: Result = %s\n", result2);
    free(result2);

    return 0;
}