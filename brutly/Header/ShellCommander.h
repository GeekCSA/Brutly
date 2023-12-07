#include <utility>

//
// Created by moshe on 31/10/2023.
//

#pragma once

#ifndef UNTITLED_SHELLCOMMANDER_H
#define UNTITLED_SHELLCOMMANDER_H

class RunningResult{

public:
    const int ExitCode;
    const std::string Verbose;
    const std::string AdditionalInfo;

    //strings without '&' because there is a move ctor
    RunningResult(const int exitCode, std::string verbose, std::string additionalInfo = "")
                : ExitCode(exitCode), Verbose(std::move(verbose)), AdditionalInfo(std::move(additionalInfo)) {}
};

class ShellCommander {
public:
    RunningResult run(const std::string& cmd) const;
    RunningResult run(const std::string& cmd, std::ofstream& outfile) const;
};


#endif //UNTITLED_SHELLCOMMANDER_H