/*************************************************************************************
* Copyright (c) 2019 xffish
* c_plus_plus_primer_exercise is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
* See the Mulan PSL v2 for more details.
*************************************************************************************/

//在t10.16上修改
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void biggies(vector<string> &words, std::string::size_type sz);
void elimDups(vector<string> &mvec);
string make_plural(int ctr, const string &word, const string &ending);

int main()
{
    vector<string> mvec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(mvec, 5);
}

// 原书示例sz的类型是vector<string>::size_type，更严谨，不过我这里就这样写了
//但这样编译时对“{ return str.size() < sz; };”会有警告，这里还是改过来
void biggies(vector<string> &words, std::string::size_type sz)
{
    elimDups(words);
    auto compareLength = [](const string &left, const string &right) { return left.size() < right.size(); };
    stable_sort(words.begin(), words.end(), compareLength);
    //此时words已经是先按长度排，长度相同按字典序排，去除了重复元素的容器
    //这是本题关键
    //return里面大小判断改了，要保持小的在前面
    auto searchSize = [sz](const string &str) { return str.size() < sz; };
    //这里从cbegin改为begin，partition不能接受cbegin，cend改end同理
    //iter1类型就不是const_iterator了
    auto iter1 = std::partition(words.begin(), words.end(), searchSize);

    //计算满足size>=sz的元素数目
    auto count = words.cend() - iter1;
    //根据count打印“word”单词的单数或者复数形式
    cout << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    //iter1不是const_iterator，导致cend也要改为end
    std::for_each(iter1, words.end(), [](const string &s) { cout << s << " "; });
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