#include <iostream>
#include <forward_list>
#include <string>

using std::string;
using std::forward_list;
using std::cout;
using std::endl;
using std::advance;
using std::distance;

void process(forward_list<string>& flst, const string& str1, const string& str2);

int main()
{
    //查第一个string，把第二个插入到第一个后面

    //如果第一个string不存在，把第二个插到链表末尾
    forward_list<string> flst = {"aqi","xiaoli","123","luma","tiantian","maomao",};
    process(flst, "123", "456");
    for(auto item : flst)
    {
        cout << item << endl;
    }
    return 0;
}

/**
 *查第一个string，把第二个插入到第一个后面
 *如果第一个string不存在，把第二个插到链表末尾
*/
void process(forward_list<string>& flst, const string& str1, const string& str2)
{
    auto prev = flst.cbefore_begin();
    auto curr = flst.cbegin();
    while(curr != flst.cend())
    {
        if(*curr == str1) //找到了
        {
            flst.insert_after(curr, str2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    if(curr == flst.cend())
    {
        //说明没找到str1，或者flst是空的，模拟push_back
        auto it = flst.cbegin();
        // advance(it, -1); //不能倒着
        //把it移动到最后一个元素上
        //distance(begin(), end())，看forward_list有几个元素
        advance(it, distance(flst.cbegin(), flst.cend()) - 1);
        it = flst.insert_after(it, str2);
    }

}