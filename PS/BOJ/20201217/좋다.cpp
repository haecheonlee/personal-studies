#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> a(N);
	map<int,int> b;
	map<int,bool> check;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		
		b[a[i]]++;
		check[a[i]] = false;
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int sum = a[i] + a[j];

			if(a[i] == 0 && a[j] == 0 && b[0] <= 2) continue;			
			if(sum == a[i] && b[sum] == 1) continue;
			if(sum == a[j] && b[sum] == 1) continue;
			
			if(b.find(sum) != b.end() && check[sum] == false) 
				ans += b[sum], check[sum] = true;
		}
	}
	cout << ans << '\n';

	return 0;
}
