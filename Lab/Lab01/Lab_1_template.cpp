#include <iostream>

int main() {
    int num1, num2;
    
    std::cout << "Please enter the first number: ";
    std::cin >> num1;
    
    std::cout << "Please enter the second number: ";
    std::cin >> num2;
    
    int sum = num1 + num2;
    
    std::cout << "두 숫자의 합: " << sum << std::endl;
    
    return 0;
}

