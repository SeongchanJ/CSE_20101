#include <iostream>

int main() {
    int num1, num2;
    
    std::cout << "첫 번째 숫자를 입력하세요: ";
    std::cin >> num1;
    
    std::cout << "두 번째 숫자를 입력하세요: ";
    std::cin >> num2;
    
    int sum = num1 + num2;
    
    std::cout << "두 숫자의 합: " << sum << std::endl;
    
    return 0;
}

