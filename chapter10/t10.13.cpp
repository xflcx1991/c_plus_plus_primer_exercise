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
    //习惯上迭代器终止条件应该写为 iterItem != iter，不过我自己这样写习惯了
    for (auto iterItem = mvec.cbegin(); iterItem < iter; ++iterItem)
    {
        cout << *iterItem << endl;
    }

    return 0;
}

bool isLengthGreaterFive(const string &str)
{
    const int LIMIT = 5;
    //用三目运算符岂不是闲的了，还是删掉 2020年2月13日
    // return str.size() >= LIMIT ? true : false;
    return str.size() >= LIMIT;
}