/* reference: beakjoon/codeplus */

#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;

	if(N % 5 == 0 || N % 5 == 2) cout << "CY";
	else cout << "SK" ;

	return 0;
}
