#include <iostream>
#include <list>
#include <deque>
#include <string>

using std::list;
using std::deque;
using std::string;
using std::cout;
using std::endl;

int main()
{
    list<int> mlist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> oddDeque;
    deque<int> evenDeque;
    for(auto item : mlist)
    {
        if(item % 2 == 0)
        {
            //偶数
            evenDeque.push_back(item);
        }
        else
        {
            oddDeque.push_back(item);
        }
        
    }

    cout << "奇数deque" << endl;
    for(auto item : oddDeque)
    {
        cout << item << " ";
    }
    cout << endl;

    cout << "偶数deque" << endl;
    for(auto item : evenDeque)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
