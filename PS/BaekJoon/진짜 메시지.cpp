#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	string M;
	for(int i=0; i<T; i++) {
		cin>>M;
		
		map<char, int> _m;
		string new_msg="";
		for(int j=0; j<M.size(); j++) {
			new_msg += M[j];
			_m[M[j]]++;
			
			if(_m[M[j]] == 3) {
				_m[M[j]] = 0;
				new_msg += M[j];
				j++;
			}
		}
		
		if(new_msg == M) cout<<"OK\n";
		else cout<<"FAKE\n";
	}

	return 0;
}

/*
boj.kr/9324

INPUT:
3
BAPC
AABA
ABCABCBBAAACC

OUTPUT:
OK
FAKE
OK
*/
