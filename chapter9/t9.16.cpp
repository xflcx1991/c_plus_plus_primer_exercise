#include <iostream>
#include <vector>
#include <list>

using std::list;
using std::vector;
using std::cout;
using std::endl;

int compareContainer1(const list<int> &mlist, const vector<double> &mvector);
int compareContainer2(const list<int> &mlist, const vector<double> &mvector);

int main()
{
    list<int> mlist = {
        1, 2, 3, 4, 5,
    };
    vector<double> mvector = {1.0, 2.0, 3.0, 4.0, 9.0};
    
    //1.思路一自行遍历数据比较，double怎么比较相等？？可以转成string再来比较，还是转成int比较吧
    int result = compareContainer1(mlist, mvector);
    //2. 思路二生成一个类型相同的临时容器去比较
    //compareContainer2
    // int result = compareContainer2(mlist, mvector);
    
    if (result == 0)
    {
        cout << "mlist和mvector相等" << endl;
    }
    else if (result = -1)
    {
        cout << "mlist 比 mvector 小" << endl;
    }
    else
    {
        cout << "mlist 比 mvector 大" << endl;
    }


    return 0;
}

int compareContainer1(const list<int> &mlist, const vector<double> &mvector)
{
    //1.思路一自行遍历数据比较，double怎么比较相等？？可以转成string再来比较，还是转成int比较吧
    auto head1 = mlist.cbegin();
    auto head2 = mvector.cbegin();

    int flag = 0;   //假设相等，-1：小于，1：大于
    int result = 0; //最终结果，0：相等，-1：小于，1：大于
    for (; head1 != mlist.cend() || head2 != mvector.cend(); ++head1, ++head2)
    {
        if ((*head1) == static_cast<int>(*head2))
        {
            continue;
        }
        else if ((*head1) < static_cast<int>(*head2))
        {
            flag = -1;
            break;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        if (mlist.size() == mvector.size())
        {
            //如果两个容器具有相同大小且所有元素都两两对应相等，则相等
            result = 0;
        }
        else
        {
            //两个容器大小不同，但较小容器的每个元素都等于较大的对应元素
            result = -1;
        }
    }
    else
    {
        result = flag;
    }

    return result;
    // if (result == 0)
    // {
    //     cout << "mlist和mvector相等" << endl;
    // }
    // else if (result = -1)
    // {
    //     cout << "mlist 比 mvector 小" << endl;
    // }
    // else
    // {
    //     cout << "mlist 比 mvector 大" << endl;
    // }
}

//思路二生成一个类型相同的临时容器去比较，有危险，两个容器比double大小会有问题
int compareContainer2(const list<int> &mlist, const vector<double> &mvector)
{
    int result = 0;
    vector<double> mTempVector(mlist.begin(), mlist.end());

    if (mTempVector == mvector)
    {
        result = 0;
    }
    else if (mTempVector < mvector)
    {
        result = -1;
    }
    else
    {
        result = 1;
    }
    return result;
}