//
// Created by moshe on 09/11/2023.
//

#ifndef UNTITLED_LOGGER_H
#define UNTITLED_LOGGER_H

#include <string>
#include <ostream>
#include <ctime>
#include <sstream>


class Logger{
private:

    enum LogType { InfoType, ErrorType };

    const static std::string logo;

    std::ostream& _logStream;

    static std::string CurrentDateTime();
    static std::string BuildLog(const LogType& logType, const char* log);
public:
    //The keyword explicit is to prevent an implicit conversion of values
    explicit Logger(std::ostream& logStream);

    static std::string GetLogoString();

    size_t Info(const char* log);
    size_t Info(const std::string& log);
    size_t Error(const char* log);
    size_t Error(const std::string& log);
};

//extern Logger& loggerPtr;
extern Logger* logger;


#endif //UNTITLED_LOGGER_H