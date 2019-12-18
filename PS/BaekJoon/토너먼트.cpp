#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, a, b;
	cin>>N>>a>>b;
	
	vector<int> v;

	// swap
	if(a<b) {
		int temp = a;
		a = b;
		b = temp;
	}

	for(int i=1; i<=N; i++) {
		v.push_back(i);
	}

	int count = 1, check = false;
	while(v.size() != 1) {
		for(int i=0; i<v.size(); i+=2) {
			
			if(i != v.size() -1) {
				if(a == v[i+1] && b == v[i]) {
					check = true;
					break;
				} else {
					int index = 0;
					
					if(v[i] == a || v[i] == b) index = i+1;
					else index = i;
					
					v.erase(v.begin() + index);
					i--;
				}
			}
		}

		if(check) break;
		count++;
	}
	
	if(check) cout<<count<<endl;
	else cout<<-1<<endl;

	return 0;
}

/*
boj.kr/1057

INPUT:
16 8 9

OUTPUT:
4
*/
