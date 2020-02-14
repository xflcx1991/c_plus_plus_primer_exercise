#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void biggies(vector<string> &words, int sz);
void elimDups(vector<string> &mvec);
string make_plural(int ctr, const string &word, const string &ending);

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(mvec, 5);
}

// 原书示例sz的类型是vector<string>::size_type，更严谨，不过我这里就这样写了
void biggies(vector<string> &words, int sz)
{
    elimDups(words);
    auto compareLength = [](const string &left, const string &right) { return left.size() < right.size(); };
    stable_sort(words.begin(), words.end(), compareLength);
    //此时words已经是先按长度排，长度相同按字典序排，去除了重复元素的容器
    //获取一个迭代器，指向第一个满足size()>=sz的元素
    auto searchSize = [sz](const string &str) { return str.size() >= sz; };
    auto iter1 = std::find_if(words.cbegin(), words.cend(), searchSize);
    //计算满足size>=sz的元素数目
    auto count = words.cend() - iter1;
    //根据count打印“word”单词的单数或者复数形式
    cout << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    std::for_each(iter1, words.cend(), [](const string &s) { cout << s << " "; });
    cout << endl;
}

/*
 * 去重，隐含着有按字典排序
 */
void elimDups(vector<string> &mvec)
{
    std::sort(mvec.begin(), mvec.end());
    //去除重复的单词
    auto iter = std::unique(mvec.begin(), mvec.end());
    mvec.erase(iter, mvec.cend());
}

string make_plural(int ctr, const string &word,
                   const string &ending)
{
    return (ctr == 1) ? word : word + ending;
}