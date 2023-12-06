//
// Created by moshe on 12/1/23.
//

#pragma once

#include "../Header/Exception.h"

const char * invalidCommandException::what() const noexcept {
    return _verbose;
}

invalidCommandException::invalidCommandException(const char* verbose) : _verbose(verbose) { }