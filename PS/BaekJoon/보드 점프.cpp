#include <iostream>
#include <vector>

using namespace std;

int N;
int a[101][101];
string d[101][101];

string getSum(string num1, string num2) {
	// always num1 is longer
	if(num1.size()<num2.size()) swap(num1,num2);
	
	vector<int> a,b;
	vector<int> result(105,0);
	
	for(int i=(int)num1.size()-1; i>=0; i--) a.push_back(num1[i]-'0');	
	for(int i=(int)num2.size()-1; i>=0; i--) b.push_back(num2[i]-'0');
	
	int len=min(num1.size(), num2.size());
	for(int i=0; i<len; i++) {
		int mix=(a[i]+b[i]+result[i]);
		result[i]=mix%10;
		result[i+1]+=mix/10;
	}
	
	for(int i=len; i<num1.size(); i++) {
		int mix=(a[i]+result[i]);
		result[i]=(mix%10);
		result[i+1]+=(mix/10);
	}
	
	string sum="";
	while(result.back()==0) result.pop_back();
	for(int i=(int)result.size()-1; i>=0; i--) sum+=(result[i]+'0');

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>a[i][j];
			d[i][j]="0";	
		}
	}
	
	d[0][0]="1";
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(a[i][j]==0) continue;

			int right=j+a[i][j];
			int down=i+a[i][j];
			
			if(right<N) d[i][right]=getSum(d[i][right], d[i][j]);
			if(down<N) d[down][j]=getSum(d[down][j], d[i][j]);
		}
	}
	
	cout<<d[N-1][N-1];

	return 0;
}
