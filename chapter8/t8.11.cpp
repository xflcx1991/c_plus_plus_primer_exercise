// #include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    //放到循环外声明变量
    istringstream record;

    while (getline(cin, line))
    {
        PersonInfo info;
        //这是本题关键
        //1.
        record.str(line);
        //2.上一次循环已经进入了eof状态，这一次要清掉。居然还有移动指针到流头的效果
        record.clear();

        record >> info.name;

        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    cout << "people共有多少个元素：" << people.size() << endl;
    //打印people 信息
    for (auto item_people : people)
    {
        cout << item_people.name << ",";
        for (auto item_phone : item_people.phones)
        {
            cout << item_phone << ",";
        }
        cout << endl;
    }
    return 0;
}