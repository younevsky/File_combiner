#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string inputFolderPath, outputFilePath;

    std::cout << "[+] Enter the input folder path(must be in the same directory): ";
    std::cin >> inputFolderPath;

    std::cout << "\n[+] Enter the output file path(don't forget the file extension): ";
    std::cin >> outputFilePath;

    std::ofstream outputFile(outputFilePath, std::ios::binary);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    try {
        for (const auto &entry : fs::directory_iterator(inputFolderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                std::ifstream inputFile(entry.path(), std::ios::binary);

                if (inputFile.is_open()) {
                    const size_t bufferSize = 4096;
                    char buffer[bufferSize];

                    while (inputFile.read(buffer, bufferSize)) {
                        outputFile.write(buffer, inputFile.gcount());
                    }

                    outputFile.write(buffer, inputFile.gcount());

                    inputFile.close();
                } else {
                    std::cerr << "Error: Unable to open input file: " << entry.path() << std::endl;
                }
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        outputFile.close();
        return 1;
    }

    outputFile.close();
    std::cout << "\n\n[+]Files combined successfully![+]\n" << std::endl;

    // Wait for the user to press Enter before exiting
    std::cout << "Press Enter to exit the program...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
