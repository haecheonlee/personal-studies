/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

char l[300001];
char r[300001];
int ln=0;
int rn=0;
char a[31];
char ar[31];
char b[300001];
int N,M;

bool check(int where) {
	// from front
	char *stack=l;
	char *str=ar;
	int len=ln;
	
	// from back
	if(where==1) {
		stack=r;
		str=a;
		len=rn;
	}
	
	if(len-N<0) return false;
	
	for(int i=0; i<N; i++) {
		if(stack[len-i-1]!=str[i]) return false;
	}
	
	if(where==0) ln-=N;
	else rn-=N;
	
	return true;
}

int main() {
	cin>>a;
	N=strlen(a);
	
	// reverse string
	for(int i=0; i<N; i++) ar[i]=a[N-i-1];
	
	cin>>b;
	M=strlen(b);
	
	int left=0;
	int right=M-1;
	int where=0;
	while(left<=right) {
		if(where==0) l[ln++]=b[left++];
		else r[rn++]=b[right--];
		
		if(check(where)) where=1-where;
	}
	
	for(int i=ln-1; i>=0; i--) {
		r[rn++]=l[i];
		check(1);
	}
	for(int i=rn-1; i>=0; i--) cout<<r[i];
	
	return 0;
}
