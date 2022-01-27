void build(int rt, int L, int R, vector<int> &v)
{
    if (qL <= L && R <= qR)
    {
        seg[rt] = v[L];
        return;
    }
    int M = (L + R) >> 1;
    build(LC(rt), L, M, v);
    build(RC(rt), M + 1, R, v);
    seg[rt] = seg[LC(rt)] + seg[RC(rt)];
}