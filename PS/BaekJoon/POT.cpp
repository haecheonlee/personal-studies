#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	string str_num;
	int result = 0;
	for(int i=0; i<N; i++) {
		cin>>str_num;
		int num = stoi(str_num.substr(0, str_num.size() - 1), nullptr);
		int p = stoi(str_num.substr(str_num.size() - 1), nullptr);
		
		result += pow(num, p);
	}
	
	cout<<result<<endl;

	return 0;
}

/*
boj.kr/11772

INPUT:
3
213
102
45

OUTPUT:
10385
*/
