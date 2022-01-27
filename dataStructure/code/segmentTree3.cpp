int query(int rt, int L, int R, int qL, int qR)
{
    if (qL <= L && R <= qR)
        return seg[rt];
    int M = (L + R) >> 1;
    if (qR < M + 1)
        return query(LC(rt), L, M, qL, qR);
    else if (M < qL)
        return query(RC(rt), M + 1, R, qL, qR);
    else
        return query(LC(rt), L, M, qL, qR) + query(RC(rt), M + 1, R, qL, qR);
}