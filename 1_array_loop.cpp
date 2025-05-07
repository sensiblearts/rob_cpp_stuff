#include <iostream>
int main() {
    const int size = 5;
    int numbers[size] = {10, 20, 30, 40, 50};
  
    for (int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
      
    std::cout << "NOW, see:   2_vector_loop.cpp" << std::endl;

    return 0;
}