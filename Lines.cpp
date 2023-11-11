#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr << "Error";
        return 1;
    } 
    std::ifstream file(argv[1]);
    if(!file.is_open()){
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::string line;
    int line_amount = 0;
    std::vector<std::string> lines;

    while(std::getline(file,line)){
        lines.push_back(line);
         ++line_amount;
    }
    
    std::cout << "Number of lines is: "<< line_amount << std::endl;

    std::ofstream new_file("output.txt");
    if (!new_file.is_open()) {
        std::cerr << "Erro" << std::endl;
        return 1;
    }

    for (int i=lines.size() - 1; i >= 0; i--) {
        new_file << lines[i] << std::endl;
    }
    new_file.close();
    file.close();
    return 0;
}
