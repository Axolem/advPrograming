#include <iostream>
#include <cmath>

int main() {

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << std::endl;

    if (number % 2 == 0) {
        std::cout << "Is Even";
    } else {
        std::cout << "Is Odd";
    }

    std::cout << std::endl;

    int side_a, side_b, side_c;
    std::cout << "Enter size lengths if the triangle: ";
    std::cin >> side_a >> side_b >> side_c;

    if (side_a == side_b && side_b == side_c) {
        std::cout << "Equilateral Triangle.";
    } else {
        if (side_a != side_b && side_a != side_c && side_b != side_c) {
            std::cout << "Scalene Triangle.";
        } else {
            std::cout << "Isosceles Triangle.";
        }
    }

//    // Swap the value of 2 variables
//    int a = 20;
//    int b = 30;

    // Swap the value of 2 variables without a third variable
    int a = 20;
    int b = 30;

    a = a + b; // 50
    b = a - b; // 20
    a = a - b; // 30

    // Ternary operator
    std::string message = a == b ? "Equal" : "Not equal";

    std::cout << message << std::endl;

    while (a >= 1) {
        switch (a % 2) {
            case 0:
                std::cout << "Even" << std::endl;
                break;
            default:
                std::cout << "Odd" << std::endl;
                break;
        }
        a--;
    }

    return abs(10);
}