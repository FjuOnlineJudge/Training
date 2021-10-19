struct Transportation
{
    string color;
    void printColor()
    {
        cout << "The transportation's color is " + color + ".\n";
    }
    void printColor(int year) // overload
    {
        cout << "These transportation was made in" + year + ".\n";
        cout << "These transportation's color is " + color + ".\n";
    }
};

struct Car: Transportation{
    void printColor() // override
    {
        cout << "The car's color is " + color + ".\n";
    }   
};