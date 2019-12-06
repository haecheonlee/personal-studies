#include <iostream>

using namespace std;

class Queue {
private:
    int rear, capacity;
    int *queue;
public:
    Queue(int c) {
        rear = 0;
        capacity = c;
        queue = new int;
    }
    
    ~Queue() { delete[] queue; }
    
    void enqueue(int data) {
        if(capacity == rear) {
            cout << "Queue is full" << endl;
        } else {
            queue[rear++] = data;
        }   
    }
    
    void dequeue() {
        if(rear == 0) {
            cout << "Queue is empty" << endl;
        } else {
            for(int i=0; i<rear-1; i++) {
                queue[i] = queue[i+1];
            }
            
            queue[rear-1] = 0;
            rear--;
        }
    }
    
    void display() {
        int i;
        if (rear == 0) {
            cout << "Queue is empty" << endl;
        }else {
            for(int i=0; i<rear; i++) {
                cout<< queue[i] << " ";
            }
            cout<<endl;
        }
    }
    
    int front() {
        if(rear == 0) return -1;
        else return queue[0];
    }
    
    int back() {
        if(rear == 0) return -1;
        else return queue[rear - 1];
    }
};

int main()
{
    Queue q(10);
    
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(52);
    q.enqueue(27);

    q.display();
    
    q.dequeue();
    q.dequeue();
    
    q.display();

    cout<<"Front is "<<q.front()<<endl;
    
    q.enqueue(82);
    
    q.display();
    
    cout<<"Back is "<<q.back()<<endl;
    
    return 0;
}
