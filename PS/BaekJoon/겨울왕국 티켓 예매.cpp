#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	int N, M;
	for(int i=0; i<T; i++) {
		cin>>N>>M;
		
		if(N < 13) {
			cout<<-1<<endl;
		} else {
			int result = ((N-2) * M) + 4;
			cout<<result<<endl;
		}
	}

	return 0;
}

/*
boj.kr/18247

INPUT:
2
13 5
10 9

OUTPUT:
59
-1
*/
