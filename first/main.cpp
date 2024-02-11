#include <iostream>

using namespace std;

int main() {

    // Variables
    int axole = 10;
    double age = 52.5;

    const double PI = 3.14; // Constants

    double total = axole + age;

    total += 10;


    // Exercise
    double x = 10;
    double y = 5;

    double z = (x + 10) / (3 * y);
    // std::cout << z ;

    // Writing to console
    // std::cout << x;
    // std::cout << "x = ";

//    ::cout << "x = " << x << ::endl << "y = " << y;

    // Exercise
    double sales = 95000;
    const double state_tax = 4;
    const double country_tax = 2;

    double total_tax = (sales * (state_tax / 100)) + (sales * (country_tax / 100));

//    ::cout << "Sales: $" << sales << ::endl
//           << "State tax: " << state_tax << "%" << ::endl
//           << "Country tax: " << country_tax << "%" << ::endl
//            << "Total Tax: $" << total_tax << ::endl;


//cout << "Enter a values : ";
//int value;
//cin >> value;
//
//cout << "The value is: " << value;


    cout << "Fahrenheit: ";
    int fahrenheit;
    cin >> fahrenheit;
    double celsius = (fahrenheit - 32) / 1.8;
    cout << "Celsius: " << celsius;

    return 0;
}
