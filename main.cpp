#include <iostream>
#include <cstdlib>

int main(int argc,char* argv[]){
if(argc != 4){
	std::cout << "Error" << std::endl;
	exit(EXIT_FAILURE);
}

int a = std::stod(argv[1]);
int b = std::stod(argv[2]);
int c = std::stod(argv[3]);

int min = a;
int max = a;

if(b < min){
	min = b;
	if(c < min){
		min = c;
	}
}


if(b > max){
        max = b;
        if(c > max){
                max = c;
        }
}

std::cout << "min is" << min << "max is" << max;

return 0;

}

