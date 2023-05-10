//
// Created by Denis on 5/9/2023.
//

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <exception>
#include <string>


class Exception : public std::exception {
private:
    std::string message;
public:
    explicit Exception(const std::string& message_);

};
class FontNotFound : public Exception{
public:
    FontNotFound(): Exception("Font not found in files"){}
};
class WindowNotOpened : public Exception{
public:
    WindowNotOpened(): Exception("The window could not be opened"){}
};


#endif //OOP_EXCEPTION_H
