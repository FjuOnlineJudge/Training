void push(int rt, int L, int R)
{
    if(tag[rt]==-1)
        return;
    int M = (L + R) >> 1;
    tag[LC(rt)] = tag[rt];
    seg[LC(rt)] = (M - L + 1) * tag[rt];
    tag[RC(rt)] = tag[rt];
    seg[RC(rt)] = (R - M) * tag[rt];
    tag[rt] = -1;
}

void update(int rt, int L, int R, int qL, int qR, int val)
{
    if (qL <= L && R <= qR)
    {
        seg[rt] = (R - L + 1) * val;
        tag[rt] = val;
        return;
    }
    push(rt, L, R);
    int M = (L + R) >> 1;
    if (qL <= M)
        update(LC(rt), L, M, qL, qR, val);
    if (M + 1 <= qR)
        update(RC(rt), M + 1, R, qL, qR, val);
    seg[rt] = seg[LC(rt)] + seg[RC(rt)];
}

int query(int rt, int L, int R, int qL, int qR)
{
    if (qL <= L && R <= qR)
        return seg[rt];
    push(rt, L, R);
    int M = (L + R) >> 1;
    if (qR < M + 1)
        return query(LC(rt), L, M, qL, qR);
    else if (M < qL)
        return query(RC(rt), M + 1, R, qL, qR);
    else
        return query(LC(rt), L, M, qL, qR) + query(RC(rt), M + 1, R, qL, qR);
}