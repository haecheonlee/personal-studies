class Stack {
private:
    int *elems;
    int pos;
public: 
    Stack() {
        this->elems = new int[100001] {0};
        this->pos = 0;
    }
    
    ~Stack() {
        delete[] this->elems;
    }
    
    void push(int x) {
        this->elems[++this->pos] = x;
    }
    
    int pop() {
        if(this->pos == 0) return -1;
        int popped_element = this->elems[this->pos];
        this->elems[this->pos--] = 0;
        return popped_element;
    }
    
    int size() {
        return this->pos;
    }
    
    bool empty() {
        if(this->pos == 0) return true;
        else return false;
    }
    
    int top() {
        if(this->pos == 0) return -1;
        else return this->elems[this->pos];
    }
};
