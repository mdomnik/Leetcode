#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int pos1 = 0; pos1 < numsSize - 1; pos1++)
        for (int pos2 = pos1 + 1; pos2 < numsSize; pos2++)
        {
            if (nums[pos1] + nums[pos2] == target)
            {
                result[0] = pos1;
                result[1] = pos2;
                return (result);
            }
        }
    return (NULL);
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 18;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No two elements add up to the target.\n");
    }

    return 0;
}