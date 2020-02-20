#include <iostream>
#include <vector>

using namespace std;

int largest=-1000000001, smallest=1000000001;
int nums[12], n;
int list[11], cnt[10]{0};
vector<char> operators {'+','-','*','/'};

int getOperandNumber(char op) {
	if(op=='+') return 0;
	if(op=='-') return 1;
	if(op=='*') return 2;
	if(op=='/') return 3;
}

void go(int index, int end) {
	if(index==end) {
		int sum=0;
		for(int i=0; i<n-1; i++) {
			if(operators[list[i]]=='+') sum=((i>0)?(sum+nums[i+1]):(nums[i]+nums[i+1]));
			else if(operators[list[i]]=='-') sum=((i>0)?(sum-nums[i+1]):(nums[i]-nums[i+1]));
			else if(operators[list[i]]=='*') sum=((i>0)?(sum*nums[i+1]):(nums[i]*nums[i+1]));
			else if(operators[list[i]]=='/') sum=((i>0)?(sum/nums[i+1]):(nums[i]/nums[i+1]));
		}

		largest=max(largest,sum);
		smallest=min(smallest,sum);
		
		return;
	}
	
	for(int i=0; i<4; i++) {
		int currentOperatorNumber=getOperandNumber(operators[i]);
		if(cnt[currentOperatorNumber]>0) { 
			cnt[currentOperatorNumber]--;
			list[index]=currentOperatorNumber;
			go(index+1,end);
			cnt[currentOperatorNumber]++;
		}
	}
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>nums[i];

	int m;
	for(int i=0; i<4; i++) {
		cin>>m;
		while(m--) cnt[i]++;
	}

	go(0,n-1);
	cout<<largest<<'\n'<<smallest;

	return 0;
}

/*
boj.kr/14888

INPUT:
6
1 2 3 4 5 6
2 1 1 1

OUTPUT:
54
-24
*/
