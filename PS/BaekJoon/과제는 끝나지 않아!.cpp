#include <iostream>
#include <vector>

using namespace std;

class Homework {
public:
	int score;
	int time;
	Homework(int s, int t) : score{s}, time{t}{}
};

void checkHomework(vector<Homework> &vec, int &total) {
	int last_index=vec.size()-1;
	if(vec[last_index].time==0) {
		total+=vec[last_index].score;
		vec.erase(vec.begin()+last_index);
	}
}

int main() {
	int n,total=0,time=0;
	cin>>n;
	
	int start,a,t;
	vector<Homework> vec;
	
	for(int i=0; i<n; i++) {
		cin>>start;
		
		if(start==1) {
			cin>>a>>t;
			vec.push_back({a,t-1});
			checkHomework(vec,total);
		} else {
			if(vec.size()>0) {
				vec[vec.size()-1].time-=1;
				checkHomework(vec,total);
			}
		}
	}
	
	cout<<total;
	
	return 0;
}

/*
boj.kr/17952

INPUT:
5
1 10 3
0
1 100 2
1 20 1
0

OUTPUT:
120
*/
