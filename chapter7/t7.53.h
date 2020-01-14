class Debug
{
public:
    constexpr Debug(bool b = true) : Debug(b, b, b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
    constexpr bool any();
    constexpr void setHw(bool h);
    void setIo(bool i);
    void setOther(bool o);
private:
    bool hw;
    bool io;
    bool other;
};

constexpr bool Debug::any()
{
    return hw || io || other;
}

constexpr void Debug::setHw(bool h)
{
    hw = h;
}

void Debug::setIo(bool i)
{
    io = i;
}

void Debug::setOther(bool o)
{
    other = o;
}