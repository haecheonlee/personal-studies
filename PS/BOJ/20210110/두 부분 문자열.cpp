#include <iostream>

using namespace std;

const int MAX = 1e3 + 10;

int d[MAX][MAX];

int main() {
	string A, B;
	cin >> A >> B;

	A = "0" + A, B = "0" + B;
	int aL = A.size() - 1, bL = B.size() - 1;
	
	for(int i = 1; i <= A.size(); i++) {
		for(int j = 1; j <= B.size(); j++) {
			if(A[i] == B[j]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	
	cout << aL + bL - d[aL][bL] << '\n';
	
	return 0;
}
