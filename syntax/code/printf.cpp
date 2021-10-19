#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int i = 100;
    double d = 3.14;

    printf("%4d\n", i);
    printf("%.4d\n", i);
    printf("%.4f\n", d);

    printf("\nuse *\n");
    printf("%*d\n", 4, i);
    printf("%.*d\n", 4, i);
    printf("%.*f\n", 4, d);
}

/*
 100
0100
3.1400

use *
 100
0100
3.1400
*/