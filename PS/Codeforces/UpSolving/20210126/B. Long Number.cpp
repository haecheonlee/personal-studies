/* editorial */

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	string s;
	cin >> s;

	int a[10];
	for(int i = 1; i <= 9; i++) cin >> a[i];	

	int diff[N];
	for(int i = 0; i < N; i++) diff[i] = a[s[i] - '0'] - (s[i] - '0');

	for(int i = 0; i < N; i++) {
		if(diff[i] > 0) {
			while(i < N && diff[i] >= 0) {
				s[i] = (char)a[s[i] - '0'] + '0';
				i++;
			}
			break;
		}
	}

	for(int i = 0; i < N; i++) cout << s[i];

	return 0;
}
