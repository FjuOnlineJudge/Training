int heap[N], top = 0;
void push(int v)
{
    heap[++top] = v;
    for (int i = top; i > 1;)
    {
        if (heap[i] <= heap[i / 2])
            break;
        swap(heap[i], heap[i / 2]);
        i <<= 1;
    }
}
void pop()
{
    heap[1] = heap[top--];
    for (int i = 1; (i << 1) <= top;)
    {
        if (heap[i] < heap[i << 1])
        {
            swap(heap[i], heap[i << 1]);
            i <<= 1;
        }
        else if ((i << 1) < top && heap[i] < heap[(i << 1) + 1])
        {
            swap(heap[i], heap[(i << 1) + 1]);
            i = (i << 1) + 1;
        }
        else
        {
            break;
        }
    }
}