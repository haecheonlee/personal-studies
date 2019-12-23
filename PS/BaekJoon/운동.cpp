#include <iostream>

using namespace std;

int main() {
	int N, m, M, T, R;
	cin>>N>>m>>M>>T>>R;
	
	int count=0,current=m;
	if(current+T>M) cout<<-1;
	else {
		while(N != 0) {
			if(current+T<=M) {
				current += T;
				N--;
			} else {
				if(current-R<m) current = m;
				else current -= R;
			}
			
			count++;
		}
		
		cout<<count;
	}
	
	return 0;
}

/*
boj.kr/1173

INPUT:
5 70 120 25 15

OUTPUT:
10
*/
