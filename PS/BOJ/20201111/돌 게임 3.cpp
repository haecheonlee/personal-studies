#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

bool check[MAX];

int main() {
	int N;
	cin >> N;

	check[0] = false;
	for(int i = 1; i <= N; i++) {
		if(i - 1 >= 0 && !check[i - 1]) check[i] = true;
		if(i - 3 >= 0 && !check[i - 3]) check[i] = true;
		if(i - 4 >= 0 && !check[i - 4]) check[i] = true;
	}
	cout << (check[N] ? "SK" : "CY");

	return 0;
}
