#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isLengthGreaterFive(const string &str);

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    auto iter = std::partition(mvec.begin(), mvec.end(), isLengthGreaterFive);
    //打印出长度大于等于5的元素
    for (auto iterItem = mvec.cbegin(); iterItem < iter; ++iterItem)
    {
        cout << *iterItem << endl;
    }

    return 0;
}

bool isLengthGreaterFive(const string &str)
{
    const int LIMIT = 5;
    return str.size() >= LIMIT ? true : false;
}