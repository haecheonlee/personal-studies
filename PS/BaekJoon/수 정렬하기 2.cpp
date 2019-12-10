#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	
    int N;
    cin>>N;
    
    vector<int> list;
    int num;
    for(int i=0; i<N; i++) {
        cin>>num;
        list.push_back(num);
    }
    
    sort(list.begin(), list.end());
    
    for(int i=0; i<N; i++) {
        cout<<list.at(i)<<"\n";
    }

    return 0;
}
/*
boj.kr/2751
INPUT:
5
5
4
3
2
1

OUTPUT:
1
2
3
4
5

*/
