#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string reading_file(std::ifstream& file)
{
    std::string content, line;
    while (std::getline(file, line)) {
        content += line + " ";
    }
    return content;
}

int main()
{
    std::string inputfile;
    std::cout << "Enter filename of input (e.g. input.txt): ";
    std::cin >> inputfile;

    std::ifstream file(inputfile);
    if (!file) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::string content = reading_file(file);

    std::stringstream ss(content);
    std::string hex;
    std::string result;

    while (ss >> hex) {
        try {
        	
            char byte = static_cast<char>(std::stoi(hex, nullptr, 16));
            result += byte;
        }
        catch (...) {
            std::cerr << "Error with parsing: '" << hex << "'\n";
            return 1;
        }
    }

    std::ofstream output("output.txt");
    if (!output) {
        std::cerr << "Error with creating output.txt\n";
        return 1;
    }

    output << result;
    std::cout << "Result written in output.txt: " << result << "\n";
    return 0;
}
