//0
// Created by moshe on 12/1/23.
//

#pragma once

#include <utility>

#include "../Header/Exception.h"

const char* invalidCommandException::what() const noexcept {
    return _verbose.c_str();
}

 invalidCommandException::invalidCommandException(std::string  verbose) : _verbose(std::move(verbose)) { }