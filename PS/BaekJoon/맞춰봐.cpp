// reference: baekjoon/codeplus

#include <iostream>

using namespace std;

int N;
int sign[10][10];
int ans[10];

bool check(int index) {
	int sum=0;
	
	for(int i=index; i>=0; i--) {
		sum+=ans[i];
		
		if(sign[i][index]==0) {
			if(sum!=0) return false;
		} else if(sign[i][index]<0) {
			if(sum>=0) return false;
		} else if(sign[i][index]>0) {
			if(sum<=0) return false;
		}
	}
	
	return true;
}

bool go(int index) {
	if(index==N) return true;
	
	if(sign[index][index]==0) {
		ans[index]=0;
		return check(index) && go(index+1);
	}
	
	for(int i=1; i<=10; i++) {
		ans[index]=sign[index][index]*i;
		if(check(index) && go(index+1)) return true;
	}
	
	return false;
}

int main() {
	cin>>N;
	
	string s;
	cin>>s;
	
	int cnt=0;
	for(int i=0; i<N; i++) {
		for(int j=i; j<N; j++) {
			if(s[cnt]=='0') sign[i][j]=0;
			else if(s[cnt]=='+') sign[i][j]=1;
			else sign[i][j]=-1;
			
			cnt++;
		}	
	}
	
	go(0);
	
	for(int i=0; i<N; i++) cout<<ans[i]<<" ";
	
	return 0;
}
