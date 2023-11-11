#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Error";
        return 1;
    }

    int N = std::stod(argv[1]);
    std::string str = argv[2];

    for (int i = 1; i <= N; ++i) {
        std::string filename = "file_" + std::to_string(i) + ".txt";
        std::ofstream file(filename);
        file << str  << " " << i;
        file.close();
    }
std::cout << "Created " << N << " files with the text '" << str << "'" << std::endl;

    return 0;
}
