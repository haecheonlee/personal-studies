#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,X;
	cin>>N>>X;
	
	int MAX=N*26;
	int MIN=N;
	if(MAX<X || X<MIN) {
		cout<<"!";
	} else {
		for(int i=0; i<N; i++) {
			int max_possible=26*(N-i-1);
			for(int j=1; j<=26; j++) {
				if(X-j<=max_possible) {
					X-=j;
					cout<<(char)('A'+(j-1));
					break;
				}
			}
		}
	}

	return 0;
}
