#include <istream>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

std::istream& readDataFromStream(std::istream& is)
{
    cout << is.rdstate() << endl;
    string data;
    while(is >> data)
    {
        cout << data << endl;
    }
    cout << is.rdstate() << endl;
    is.clear();
    cout << is.rdstate() << endl;
    return is;
}