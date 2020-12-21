#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	char prev_color = ' ';
	int B = 0, R = 0;
	for(int i = 0; i < N; i++) {
		char color;
		cin >> color;
		
		if(prev_color != color) {
			if(color == 'B') B++; else R++;
			prev_color = color;
		}
	}
	
	cout << min(B, R) + 1;
	
	return 0;
}
