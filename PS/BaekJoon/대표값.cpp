#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int num,total=0,largest_cnt=-1,largest_value=-1;
	
	unordered_map<int,int> m;
	for(int i=0; i<10; i++) {
		cin>>num;
		total+=num;
		
		m[num]++;
		if(m[num]>largest_cnt) {
			largest_value=num;
			largest_cnt=m[num];
		}
	}
	
	cout<<total/10<<'\n'<<largest_value;
		
	return 0;
}

/*
boj.kr/2592

INPUT:
10
40
30
60
30
20
60
30
40
50

OUTPUT:
37
30
*/
