#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void elimDups(vector<string> &mvec);
bool isShorter(const string &s1, const string &s2);

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(mvec);
    //再按长度排序
    std::stable_sort(mvec.begin(), mvec.end(), isShorter);
    cout << "======" << endl;
    for (const auto &item : mvec)
    {
        cout << item << endl;
    }
    return 0;
}

/*
 * 去重，隐含着有排序
 */
void elimDups(vector<string> &mvec)
{
    std::sort(mvec.begin(), mvec.end());
    //去除重复的单词
    auto iter = std::unique(mvec.begin(), mvec.end());
    mvec.erase(iter, mvec.cend());

    for (const auto &item : mvec)
    {
        cout << item << endl;
    }
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}