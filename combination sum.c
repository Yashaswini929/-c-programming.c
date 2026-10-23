void dfs(int* c, int n, int start, int remain, int* path, int len,
         int** res, int* returnSize, int* colSizes)
{
    if (remain == 0)
    {
        res[*returnSize] = (int*)malloc(len * sizeof(int));
        for (int i = 0; i < len; i++) res[*returnSize][i] = path[i];
        colSizes[*returnSize] = len;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < n; i++)
      {
        if (c[i] > remain) continue;
        path[len] = c[i];
        dfs(c, n, i, remain - c[i], path, len + 1, res, returnSize, colSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes)
{
    int** res = (int**)malloc(200 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(200 * sizeof(int));
    *returnSize = 0;
    int path[200];

    dfs(candidates, candidatesSize, 0, target, path, 0, res, returnSize, *returnColumnSizes);
    return res;
}
