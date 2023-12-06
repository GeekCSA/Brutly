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
    const char *_verbose;
public:

    explicit invalidCommandException(const char * verbose);
    const char * what() const noexcept override;
};

#endif //UNTITLED_EXCEPTION_H