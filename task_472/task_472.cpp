#include <iostream>
#include <fstream>

void sort(int arr[],int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main()
{

    int child, sweet;

    std::ifstream Values("input.txt");
    Values >> child >> sweet;
    
    int* ch = new int[child] {};

    for (int i = 0; i < child; ++i) {
        Values >> ch[i];
    }

    Values.close();

    while (sweet != 0) {
        sort(ch, child);
        ch[0]++;
        sweet--;
    }

    sort(ch, child);
    std::cout << ch[0];

    std::ofstream result("output.txt");
    result << ch[0];
    result.close();
}
