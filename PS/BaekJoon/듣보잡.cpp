#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, count=0;
	cin>>N>>M;
	
	map<string, int> m;
	string name;
	for(int i=0; i<N; i++) {
		cin>>name;
		m[name]=0;
	}
	
	for(int i=0; i<M; i++) {
		cin>>name;
		if(m.find(name) != m.end()) {
			count++;
			m[name]=1;
		}
	}
	
	cout<<count<<'\n';
	for(const auto &e : m) {
		if(e.second==1) cout<<e.first<<'\n';
	}

    return 0;
}

/*
boj.kr/1764

INPUT:
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

OUTPUT:
2
baesangwook
ohhenrie
*/
