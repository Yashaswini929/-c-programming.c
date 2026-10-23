void backtrack(int* nums, int n, int start, int** res, int* returnSize, int* colSizes)
{
    if (start == n)
    {
        res[*returnSize] = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) res[*returnSize][i] = nums[i];
        colSizes[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < n; i++)
      {
        int t = nums[start]; nums[start] = nums[i]; nums[i] = t;
        backtrack(nums, n, start + 1, res, returnSize, colSizes);
        t = nums[start]; nums[start] = nums[i]; nums[i] = t;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int total = 1;
    for (int i = 2; i <= numsSize; i++) total *= i;

    int** res = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, res, returnSize, *returnColumnSizes);
    return res;
}
