#include <stdio.h>

struct romanNums 
{
    char    Roman;
    int     Num;
};

void populate(struct romanNums *Nbrs)
{
    Nbrs[0] = (struct romanNums) {'I', 1};
    Nbrs[1] = (struct romanNums) {'V', 5};
    Nbrs[2] = (struct romanNums) {'X', 10};
    Nbrs[3] = (struct romanNums) {'L', 50};
    Nbrs[4] = (struct romanNums) {'C', 100};
    Nbrs[5] = (struct romanNums) {'D', 500};
    Nbrs[6] = (struct romanNums) {'M', 1000};
}

int getValue(struct romanNums *Nbrs, char c) {
    for (int i = 0; i < 7; i++) {
        if (Nbrs[i].Roman == c) {
            return Nbrs[i].Num;
        }
    }
    return 0;
}

int romanToInt(char* s) 
{
    int result = 0;
    int prev = 0;
    struct romanNums romanValues[7];
    populate(romanValues);
    while (*s != '\0')
    {
        int current = getValue(romanValues, *s);
        if (current > prev) 
            result += current - 2 * prev;
        else 
            result += current;
        prev = current;
        s++;
    }
    return (result);
}

int main() {
    char romanNum[] = "CMIV"; // Roman numeral to test (14)
    int result = romanToInt(romanNum);
    
    printf("Roman Numeral: %s\n", romanNum);
    printf("Integer Value: %d\n", result);
    
    return 0;
}