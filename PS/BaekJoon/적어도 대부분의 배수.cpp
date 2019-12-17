#include <iostream>
#include <vector>
#include <algorithm>

#define COUNT 5

using namespace std;

int main() {
	vector<int> v;
	
	int num;
	for(int i=0; i<COUNT; i++) {
		cin>>num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	int n = v[0];
	while(1) {
		int count = 0;
		for(int i=0; i<COUNT; i++) {
			if(n % v[i] == 0) count++;
			if(count == 3) break;
		}
		
		if(count == 3) break;
		n++;
	}
	
	cout<<n<<endl;

	return 0;
}

/*
boj.kr/1145

INPUT:
30 42 70 35 90

OUTPUT:
210
*/
