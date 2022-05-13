#include <iostream>
#include <fstream>


int Factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * Factorial(x - 1);
}


int main()
{
    int n = 0,
        m = 0;

    std::ifstream Values("input.txt");
    Values >> n >> m;
    Values.close();

    std::cout << n << " " << m << std::endl;
    
    int result = 0;
    for (int i = m; i <= n; ++i) {
        result += Factorial(n) / (Factorial(i) * Factorial(n - i));
    }

    std::cout << result;

}
