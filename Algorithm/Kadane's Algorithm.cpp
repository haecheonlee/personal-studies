#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadane(const vector<int>& list) {
    int global_max = list[0];
    int current_max = global_max;
    
    for(int i=1; i<list.size(); i++) {
        current_max = max(list[i], current_max+list[i]);
        if(current_max > global_max) global_max = current_max;
    }
    
    return global_max;
}

int main()
{
    vector<int> list;
    
    int N;
    cin>>N;
    
    int num;
    for(int i=0; i<N; i++) {
        cin>>num;
        list.push_back(num);
    }
    
    cout<<kadane(list)<<endl;

    return 0;
}
