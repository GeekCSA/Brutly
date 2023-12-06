//
// Created by moshe on 09/11/2023.
//

#include "../Header/Logger.h"


const std::string Logger::logo = std::string("\n") +
                                 "______               _    _\n" +
                                 "| ___ \\             | |  | |\n" +
                                 "| |_/ / _ __  _   _ | |_ | | _   _\n" +
                                 "| ___ \\| '__|| | | || __|| || | | |\n" +
                                 "| |_/ /| |   | |_| || |_ | || |_| |\n" +
                                 "\\____/ |_|    \\__,_| \\__||_| \\__, |\n" +
                                 "                              __/ |\n" +
                                 "                             |___/\n" +
                                 "\n";


Logger::Logger(std::ostream& logStream) : _logStream(logStream) { }

std::string Logger::BuildLog(const LogType& logType, const char* log){
    std::ostringstream logStream;

    switch(logType)
    {
        case InfoType : logStream << "[InfoType] - "; break;
        case ErrorType: logStream << "[ErrorType] - "; break;
    }

    logStream << " [" << CurrentDateTime() << "] - ";
    logStream << log;

    return logStream.str();
}

std::string Logger::GetLogoString(){
    return logo;
}

size_t Logger::Info(const char* log) {
    LogType logType = InfoType;

    //std::endl = add new-line + flush -> if I want more performance than remove this command
    _logStream << BuildLog(logType, log) << std::endl;
}

size_t Logger::Info(const std::string& log) {
    LogType logType = InfoType;
    _logStream << BuildLog(logType, log.c_str()) << std::endl; //c_str runtime = O(1)
}

size_t Logger::Error(const char* log) {
    LogType logType = ErrorType;
    _logStream << BuildLog(logType, log) << std::endl;
}

size_t Logger::Error(const std::string &log) {
    LogType logType = ErrorType;
    _logStream << BuildLog(logType, log.c_str()) << std::endl; //c_str runtime = O(1)
}

std::string Logger::CurrentDateTime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    char buffer[128];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %X", now);
    return buffer;
}

Logger* logger = nullptr;