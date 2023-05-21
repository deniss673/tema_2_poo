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
    virtual const char* what() const noexcept override;

};
class FontNotFound : public Exception{
public:
    FontNotFound(): Exception("Font not found in files"){}
};
class WindowNotOpened : public Exception{
public:
    WindowNotOpened(): Exception("The window could not be opened"){}
};
class InvalidMoveException : public Exception {
public:
    InvalidMoveException(): Exception("Invalid move!"){}
};
class InvalidRotate : public Exception {
public:
    InvalidRotate(): Exception("Can not rotate the piece here!"){}
};


#endif //OOP_EXCEPTION_H
