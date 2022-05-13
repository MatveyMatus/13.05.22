#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

int main()
{
	int size;
	std::ifstream Values("input.txt");
	Values >> size;

	int** Time = new int* [size] {};
	for (int i = 0; i < size; ++i) {
		Time[i] = new int[4];
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 4; ++j) {
			Values >> Time[i][j];
		}
	}

	Values.close();

	int* Time_Work = new int[size] {};

	for (int i = 0; i < size; ++i) {
		Time_Work[i] = abs(((Time[i][0] * 60) + Time[i][1]) - ((Time[i][2] * 60) + Time[i][3]));
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size-1; ++j) {
			if (Time_Work[j] < Time_Work[j + 1]) {
				int temp = Time_Work[j];
				Time_Work[j] = Time_Work[j + 1];
				Time_Work[j + 1] = temp;
			}
		}
	}
	int result = Time_Work[0];
	for (int i = 1; i < size; ++i) {
		result -= Time_Work[i];
	}

	if (result == 0) {
		result = 1440;
	}
	else if (result < 0) {
		result = 0;
	}

	std::ofstream resul("output.txt");
	resul << result;
	resul.close();

	for (int i = 0; i < size; ++i) {
		delete[] Time[i];
	}
	delete[] Time;

	delete[] Time_Work;
}

