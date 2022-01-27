void update(int rt, int L, int R, int qL, int qR, int val)
{
    if (qL <= L && R <= qR)
    {
        seg[rt] = val;
        return;
    }
    int M = (L + R) >> 1;
    if (qL <= M)
        update(LC(rt), L, M, qL, qR, val);
    if (M + 1 <= qR)
        update(RC(rt), M + 1, R, qL, qR, val);
    seg[rt] = seg[LC(rt)] + seg[RC(rt)];
}