#include <istream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

std::istream& readDataFromStream(std::istream& is);

int main()
{
    readDataFromStream(cin);
    cout << "测-试cin是否是正常的" << endl;
    //先干掉缓冲，1024是随意取的一个比较大的数字
    cin.ignore(1024, '\n');
    
    int num2 = 1;
    cin >> num2;
    cout << num2 << endl;
    cout << "确实cin流恢复正常了" << endl;
    return 0;
}