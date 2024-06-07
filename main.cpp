#include <vector>
#include <iostream>

void ten(int& a) {a = 10;}

int main(int argc, char* argv[]) {
   int i = 12;
   ten(i);
   std::cout << i << std::endl;
}