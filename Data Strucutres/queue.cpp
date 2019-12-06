#include <iostream>

using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int *queue;
public:
    Queue(int c) {
        front = rear = 0;
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
        if(front == rear) {
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
        if (front == rear) {
            cout << "Queue is empty" << endl;
        }else {
            for(int i=0; i<rear; i++) {
                cout<< queue[i] << " ";
            }
            cout<<endl;
        }
    }
    
    int getFront() {
        if(front == rear) return -1;
        else return queue[front];
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

    cout<<"Front is "<<q.getFront()<<endl;
    
    q.enqueue(82);
    
    q.display();
    
    return 0;
}
