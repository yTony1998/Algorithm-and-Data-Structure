#pragma once

#include <iosfwd>
#include <string>
class Message
{
private:
    std::string message_;
    std::ostream &printObject(std::ostream &os);
public:
    Message(const std::string &m) : message_(m) {}
    friend std::ostream &operator<<(std::ostream &os, Message &obj)
    {
        return obj.printObject(os);
    }
    Message(/* args */);
    ~Message();
};

Message::Message(/* args */)
{
}

Message::~Message()
{
}
