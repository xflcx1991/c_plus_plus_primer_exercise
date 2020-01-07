#include <iostream>
#include "t7.6.h"

using std::cout;
using std::cin;

int main()
{
    //1st
    Sales_data sd1;
    print(cout, sd1);
    //2nd
    Sales_data sd2("10001");
    print(cout, sd2);

    //3rd
    Sales_data sd3("10002", 100, 200);
    print(cout, sd3);

    //4th
    Sales_data sd4(cin);
    print(cout, sd4);
    return 0;
}
