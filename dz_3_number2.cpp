#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>

int main() {
    char sourceF[50],destinationF[50];
    int dest_1, dest_2, bytes;
  
    std::cout << "Enter the name of the source file: ";
    std::cin >> sourceF;

    std::cout << "Enter the name of the destination file: ";
    std::cin >> destinationF;

    std::cout << "Enter the initial offset in the source file (in bytes): ";
    std::cin >> dest_1;

    std::cout << "Enter the initial offset in the destination file (in bytes): ";
    std::cin >> dest_2;

    std::cout << "Enter the number of bytes to copy: ";
    std::cin >> bytes;

    int num1 = open(sourceF, O_RDONLY);
    if (num1 == -1) {
        std::cout<<"Error";
        return 1;
    }

    int num2  = open(destinationF, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if(dest_2 == -1){
        std::cout << "Error";
        return 1;
    }

    if(lseek(num1, dest_1, SEEK_SET) == -1){
        std::cout << "Error";
        return 1;
    }

    if(lseek(num2, dest_2, SEEK_SET) == -1){
        std::cout <<"Error";
        return 1;
    }

    char buffer;
    int bytesRead, i = 0;
  
    while(i < bytes) {
        bytesRead = read(num1, &buffer, sizeof(buffer));
      
        if(bytesRead <= 0) {
            break;
        }

        if(write(num2, &buffer, bytesRead) != bytesRead){
             std::cout << "Error";
             return 1;
        }

        i += bytesRead;
    }

    close(num1);
    close(num2);

    std::cout << "Successfully copied " << i  << " bytes from the source file to the destination file." << std::endl;
  
    return 0;
}
