#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getResult(int value, int power){
	vector<int> v {};
	
	int acc = 1;
	while(1) {
		acc *= value;
		int last_digit = (acc%10 == 0) ? 10 : acc%10;
		
		if(find(v.begin(), v.end(), last_digit) == v.end()) v.push_back(last_digit);
		else break;
	}
	
	int remainder = (power%v.size() == 0) ? v.size()-1 : power%v.size()-1;
	int result = v[remainder];

	return result;
}

int main() {
	int T=0;
	cin>>T;
	
	int a=0, b=0;
	for(int i=0; i<T; i++) {
		cin>>a>>b;
		
		int result = getResult(a, b);
		cout<<result<<endl;
	}

	return 0;
}

/*
boj.kr/1009

INPUT:
5
1 6
3 7
6 2
7 100
9 635

OUTPUT:
1
7
6
1
9
*/
