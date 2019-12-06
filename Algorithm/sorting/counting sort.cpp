#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    int arr[N];
    int num;
    for(int i=0; i<N; i++) {
        cin>>num;
        arr[i] = num;    
    }

    /* Counting Sort */
    int index[10001];
    
    // initializing
    for(int i=0; i<N; i++) {
        index[arr[i]]++;
    }
    
    // indexing
    for(int i=1; i<10001; i++) {
        index[i] += index[i-1];
    }
    
    // placing
    int new_arr[N];
    for(int i=0; i<N; i++) {
        new_arr[index[arr[i]] - 1] = arr[i];
        index[arr[i]]--;
    }
    
    // displaying
    for(int i=0; i<N; i++) {
        cout<<new_arr[i]<<endl;
    }
    
    return 0;
}
