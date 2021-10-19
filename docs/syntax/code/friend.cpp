struct Circle
{
  private:
    double radius;
    friend double area(Circle &);
};

double area(Circle &c) { return c.radius * c.radius * 3.14; }