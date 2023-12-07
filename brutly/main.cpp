
#include <ostream>
#include <fstream>


#include "Header/ShellCommander.h"
#include "Header/Exploits/FileReader.h"
#include "../Logger/Header/Logger.h"



int main() {

    //Set logger
    std::ofstream fileStream("logs.log");
    if (!fileStream.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }
    logger = new Logger(fileStream);

    std::string logo = Logger::GetLogoString();
    logger->Info(logo);

    ShellCommander shellCommander;
    logger->Info("Init ShellCommander successfully");

    FileReader fileReader(shellCommander);
    logger->Info("Init FileReader successfully");

    fileReader.run(0, nullptr);


    char* filePathExamples[12] = {
//            "/home/test/Downloads/file.txt",
//            "/home/test/Downloads/file",
//            "/home/test/Downloads/",
//            "/home/test/Download/",
//            "/home/test/Download",
//            "/home/test/Downloads",
//            "/home/test/Downloads/testme.txt",
//            "/home/test/Downloads/testme",
//            "/home/test/Downloads/testme.tx",
//            "/home/test/Downloads/______windows-server - Roy.rdp",
//            "/home/test/Downloads/89-6873 - למידה באמצעות חיזוקים.docx",
//            "/home/test/Downloads/89-6ssssssssssssssssssaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd873 - למידה באמצעות חיזוקים.docx"
    };

    std::cout << "Finish!" << std::endl;

    fileStream.close();

    return 0;
}