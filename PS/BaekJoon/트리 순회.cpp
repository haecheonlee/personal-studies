#include <iostream>

using namespace std;

struct Node {
	int left;
	int right;
};

Node nodes[50];

void pre_order(int idx) {
	if(idx==-1) return;
	cout<<(char)(idx+'A');
	pre_order(nodes[idx].left);
	pre_order(nodes[idx].right);
}

void in_order(int idx) {
	if(idx==-1) return;
	in_order(nodes[idx].left);
	cout<<(char)(idx+'A');
	in_order(nodes[idx].right);
}

void post_order(int idx) {
	if(idx==-1) return;
	post_order(nodes[idx].left);
	post_order(nodes[idx].right);
	cout<<(char)(idx+'A');
}

int main() {
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++) {
		char x, y, z;
		cin>>x>>y>>z;
		
		x=x-'A';
		if(y=='.') nodes[x].left=-1;
		else nodes[x].left=y-'A';
		
		if(z=='.') nodes[x].right=-1;
		else nodes[x].right=z-'A';
	}
	
	pre_order(0);
	cout<<'\n';
	in_order(0);
	cout<<'\n';
	post_order(0);

	return 0;
}

/*
boj.kr/1991

INPUT:
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

OUTPUT:
ABDCEFG
DBAECFG
DBEGFCA
*/
