#include <string>

class Screen
{
public:
    //类型成员
    using pos = std::string::size_type;

    Screen() = default;


    char get() const;
    char get(pos r, pos c) const;
    Screen& move(pos r, pos c);

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
};

char Screen::get() const
{
    return contents[cursor];
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}