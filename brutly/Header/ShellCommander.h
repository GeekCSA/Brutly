//
// Created by moshe on 31/10/2023.
//

#pragma once

#ifndef UNTITLED_SHELLCOMMANDER_H
#define UNTITLED_SHELLCOMMANDER_H

#include <string>

class RunningResult{

public:
    const int ExitCode;
    const std::string Verbose;
    const std::string AdditionalInfo;

    RunningResult(const int exitCode, const std::string& verbose, const std::string& additionalInfo = "")
                : ExitCode(exitCode), Verbose(verbose), AdditionalInfo(additionalInfo) {}
};

class ShellCommander {
public:
    RunningResult run(char* cmd) ;
    RunningResult run(char* cmd, std::ofstream& outfile) ;
};


#endif //UNTITLED_SHELLCOMMANDER_H