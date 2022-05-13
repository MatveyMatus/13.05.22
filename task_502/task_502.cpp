#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	int n;

	std::ifstream Values("input.txt");
	Values >> n;

	std::vector<std::vector<int>> Weight(1 + n, std::vector<int>(1 + n));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			Values >> Weight[i][j];
		}
	}

	Values.close();

	const int INF = -1000 * 1000 * 1000;
	std::vector<std::vector<int>> maxWeight(1 + n, std::vector<int>(1 + n, INF));
	maxWeight[0][0] = 0;
	
	for (int col = 1; col <= n; ++col) {
		for (int s = 0; s <= n; ++s) {
			maxWeight[col][s] = maxWeight[col - 1][s];
			for (int i = 1; i <= s; ++i) {
				maxWeight[col][s] = std::max(maxWeight[col][s], Weight[i][col] + maxWeight[col - 1][s - i]);
			}
		}
	}
	std::cout << maxWeight[n][n];

}

