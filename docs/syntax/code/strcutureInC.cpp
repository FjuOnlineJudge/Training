// struct
struct Item
{
    int price;
    int weight;
} apple;

struct Item banana1, banana2;
struct Item cake[10];
struct Item *itemPointer;

// class
class Item
{
  public:
    int price, weight;
    int getPrice() { return price; }
} apple;

Item banana;