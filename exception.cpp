//
// Created by Denis on 5/9/2023.
//

#include "exception.h"
#include <iostream>

Exception::Exception(const std::string& message_) : message(message_) {}

const char* Exception::what() const noexcept {
    return message.c_str();
}