//
// Created by moshe on 12/1/23.
//

#ifndef UNTITLED_EXCEPTION_H
#define UNTITLED_EXCEPTION_H

#include <exception>
#include <stdexcept>

class invalidCommandException: public std::exception
{
private:
    const std::string _verbose;
public:

    explicit invalidCommandException(std::string  verbose);
    const char * what() const noexcept override;
};

#endif //UNTITLED_EXCEPTION_H