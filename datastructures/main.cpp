#include <iostream>
#include "cstdlib"
#include "ctime"

using namespace std;

int main() {
    double  price = 99.99;
    float interest_rate = 3.67F; // Add suffix F
    long file_size = 90000L; // Add suffix L
    char letter = '1';
    bool is_valid = false;
    auto age = 21; // Automatically inferred

    int number = {}; // Best practice to use the brace initializer

    srand(time(nullptr));
    int random_number = rand() % 10;

    // Exercise
    const short min_value = 1;
    const short max_value = 6;
    int first_dice = (rand() % (max_value - min_value + 1)) + min_value;
    int second_dice = (rand() % (max_value - min_value + 1)) + min_value;

    cout << "First dice: " << first_dice << endl
        << "Second dice: " << second_dice << endl;

    return 0;
}
