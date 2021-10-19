struct Queue
{
    int q[N], head, tail;
    Queue() : head(0), tail(0) {}
    int size() { return tail - head; }
    void push(int x) { q[tail++] = x; }
    int front() { return q[head]; }
    void pop() { head++; }
}