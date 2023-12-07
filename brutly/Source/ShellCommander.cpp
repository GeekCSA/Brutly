//
// Created by moshe on 31/10/2023.
//

#include <cstdio>
#include <fstream>

#include "../Header/ShellCommander.h"

RunningResult ShellCommander::run(const std::string& cmd) const{
    return {ENOSYS, "Please implement the function"};
}

RunningResult ShellCommander::run(const std::string& cmd, std::ofstream& outfile) const {

    //TODO: Read the documentation about PIPE in c++!
    //Maybe don't use with this function. Use with other function of execl family because some of execl functions
    //behavior effected by PATH env variable etc.
    FILE* pipe = popen(cmd.c_str(), "r");

    if (pipe == nullptr) {
        return {EXIT_FAILURE, "An error occurs while creating pip for running command", cmd};
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        outfile << buffer;
    }

    int returnCode = pclose(pipe);
    std::string verbose;
    if(returnCode == EXIT_SUCCESS){
        verbose = "Close correctly the pipe for the command";
    }else{
        verbose = "Did not close correctly the pipe for the command";
    }

    return {returnCode, verbose, cmd};
}