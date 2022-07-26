void dfs(int idx, ...)
{
    ...
    dfs(i+1, ...); // choose ith element
    dfs(i+1, ...); // not to choose ith element
}