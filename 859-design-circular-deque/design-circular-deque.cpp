class MyCircularDeque {
    int* dequeue;
    int front,rear,size,capacity;
public:
    MyCircularDeque(int k) {
        capacity = k;
        dequeue = new int[capacity];
         front = 0;
         rear = capacity - 1;
         size = 0;
    }
    
    bool insertFront(int value) {
         if(isFull()){
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        dequeue[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % capacity;
        dequeue[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
          if(isEmpty()){
            return false;
        }
        front = (front + 1) % capacity;

        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
         if(isEmpty()){
             return -1;
        }
        return dequeue[front];
    }
    
    int getRear() {
        if(isEmpty()){
             return -1;
        }
        return dequeue[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */