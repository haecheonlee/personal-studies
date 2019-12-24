#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin>>s;
	
	int N;
	cin>>N;
	
	int current_index=0;
	string code;
	for(int i=0; i<N; i++) {
		cin>>code;
		if(code == "char") {
			cout<<stol(s.substr(current_index, 2), 0, 16)<<" ";
			current_index+=2;
		} else if(code == "int") {
			cout<<stol(s.substr(current_index, 8), 0, 16)<<" ";
			current_index+=8;
		} else if(code == "long_long") {
			cout<<stol(s.substr(current_index, 16), 0, 16)<<" ";
			current_index+=16;
		}
	}

	return 0;
}

/*
boj.kr/17949

INPUT:
0000020a7f0000000007000a00
3
int char long_long

OUTPUT:
522 127 117443072
*/
