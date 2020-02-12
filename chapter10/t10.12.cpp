#include "../chapter7/t7.41.h"
#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool compareIsbn(const Sales_data &lsd, const Sales_data &rsd);

int main()
{
    vector<Sales_data> mvec;
    Sales_data s1("aaa");
    Sales_data s2("azffff");
    Sales_data s3("bz");
    Sales_data s4("zoooooooooooo");
    Sales_data s5("c");

    mvec.push_back(s3);
    mvec.push_back(s1);
    mvec.push_back(s2);
    mvec.push_back(s4);
    mvec.push_back(s5);

    cout << "排序前：" << endl;
    for (const auto &item : mvec)
    {
        print(std::cout, item);
    }

    std::sort(mvec.begin(), mvec.end(), compareIsbn);

    cout << "排序后：" << endl;
    for (const auto &item : mvec)
    {
        print(std::cout, item);
    }

    return 0;
}

bool compareIsbn(const Sales_data &lsd, const Sales_data &rsd)
{
    return lsd.isbn() < rsd.isbn();
}