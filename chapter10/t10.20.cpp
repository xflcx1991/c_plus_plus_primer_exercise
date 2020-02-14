//在t10.19上修改
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    //只统计有多少单词大于等于6
    const int LENGTH = 6;
    auto searchSize = [](const string &str) { return str.size() >= LENGTH; };
    auto count = std::count_if(mvec.cbegin(), mvec.cend(), searchSize);

    //根据count打印“word”单词的单数或者复数形式
    cout << count << endl;
}
