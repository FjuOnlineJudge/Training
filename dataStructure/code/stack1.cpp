struct stack
{
    int st[N], top;
    Stack() : top(0) {}
    int size() { return top; }
    void push(int x) { st[++top] = x; }
    int top() { assert(top > 0) return st[top]; }
    void pop()
    {
        if (top)
            --top;
    }
}