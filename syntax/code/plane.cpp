struct Plane
{
    int x, y;
    // Constructor
    Plane(){};
    Plane(int _x, int _y) : x(_x), y(_y) {}
    // Operator overloading
    bool operator<(const Plane &rhs) const
    {
        if (x != rhs.x)
            return x < rhs.x;
        return y < rhs.y;
    }
    // Destructor
    ~Plane(){};
};

int main()
{
    Plane p1;
    Plane p2(1, 2);
    Plane p3 = Plane();
    Plane p4 = Plane(0, 0);
}