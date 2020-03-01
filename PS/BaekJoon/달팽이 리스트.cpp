#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m,v,k;
	cin>>n>>m>>v;
	
	vector<int> list(n);
	for(int i=0; i<n; i++) cin>>list[i];
	
	while(m--) {
		cin>>k;
		
		if(k<n) {
			cout<<list[k]<<'\n';
		} else{
			int index=(k-(v-1))%(n-(v-1));
			cout<<list[index+v-1]<<'\n';;
		}
	}

	return 0;
}

/*
boj.kr/17827

INPUT:
10 10 3
13 2 5 11 7 8 2 4 9 10
1
2
3
8
9
10
11
16
17
49

OUTPUT:
2
5
11
9
10
5
11
9
10
10
*/
