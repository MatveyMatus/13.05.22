#include <iostream>
#include <fstream>
#include <ctime>


void RandomValues() {
    srand(time(NULL));

    std::ofstream input("input.txt");
    input << rand() % 99998 + 1;
    input.close();
}

int main()
{
    RandomValues();

    long num, fact = 1;

    std::ifstream Value("input.txt");
    Value >> num;
    Value.close();
    
    for (int i = 1; i < num + 1; ++i) {
        fact *= i;
        while (fact % 10 == 0) {
            fact /= 10;
        }
        fact %= 10000;
    }
    
    std::ofstream result("output.txt");
    result << fact % 10;
    result.close();
}
