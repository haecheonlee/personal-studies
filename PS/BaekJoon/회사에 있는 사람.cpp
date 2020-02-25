#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, string, greater<string>> list;
	
	int n;
	cin>>n;
	
	while(n--) {
		string name, status;
		cin>>name>>status;
		
		list[name]=status;
	}
	
	for(auto it=list.begin(); it!=list.end(); it++) {
		if(it->second=="enter") cout<<it->first<<'\n';
	}
	
	return 0;
}

/*
boj.kr/7785

INPUT:
4
Baha enter
Askar enter
Baha leave
Artem enter

OUTPUT:
Askar
Artem
*/
