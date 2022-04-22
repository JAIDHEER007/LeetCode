#include<iostream>
using namespace std; 

class MyCircularQueue{
    private:
        int front, rear; 
        int size; 
        int *arr;

    public:
        MyCircularQueue(int k){
            size = k; 
            front = rear = 0; 
            arr = new int[size]; 

            for(int i = 0; i < size; arr[i] = -1, ++i); 
        }

        bool enQueue(int);
        bool deQueue(); 

        int Front(); 
        int Rear(); 

        bool isEmpty(); 
        bool isFull(); 
};

// Add an element to the CQ if it's not full
// Rear pointer will be increased by one and the new element will be added
// While increasing the rear pointer we will perfrom modulo by size
// This will make the rear ptr to use the front unused part thus forming a ring buffer
// If the enqueue operation is successful then return true else return false; 
bool MyCircularQueue::enQueue(int value){
    if(isFull()) return false; 
    rear = (rear + 1) % size; 
    arr[rear] = value; 
    return true; 
}

// Remove an element from the CQ if it's not empty
// Front pointer will be increased by one and the previous element pointed by rear will be replaced by -1
// While increasing the front pointer we will perfrom modulo by size
// This will make the front ptr to use the front unused part thus forming a ring buffer
// If the dequeue operation is successful then return true else return false; 
bool MyCircularQueue::deQueue(){
    if(isEmpty()) return false; 
    arr[front] = -1; 
    front = (front + 1) % size; 
    return true; 
}

// Return the front element if the CQ is not empty
// Else return -1; 
int MyCircularQueue::Front(){
    return (isEmpty())?(-1):(arr[front]); 
}

// Return the rear element if the CQ is not empty
// Else return -1; 
int MyCircularQueue::Rear(){
    return (isEmpty())?(-1):(arr[rear]); 
}

// Return true if the CQ is FULL
// There should be no empty space and no further insertions possible into CQ
// if the front is at zero and rear is at (size - 1) then the CQ is filled so return true
// Another condition will be (rear + 1) should be equal to front
// In both the cases the CQ is full
// We can simply rewrite the the above 2 conditions as ((rear + 1) % size == front)
// But the there is another condition to check inorder to avoid colision with isEmpty() function
// isEmpty() also uses similar conditions for checking if the CQ is Empty() or not
// So if the ((rear + 1) % size == front) holds true and arr[rear] is not -1 
// then the CQ is really full
bool MyCircularQueue::isFull(){
    if((rear + 1) % size == front)
        return arr[rear] != -1; 
    return false; 
}

// Return True if CQ isEmpty()
// There should be no element present in the Queue
// Another case to be checked is front and rear equals to -1
// This is the case where the CQ is created and no new elements are inserted
bool MyCircularQueue::isEmpty(){
    if((front == -1) && (rear == -1))
        return true; 
    if((rear + 1) % size == front)
        return arr[rear] == -1; 
    return false; 
}

int main(){
    MyCircularQueue cq1(3); 

    cout<<boolalpha<<cq1.enQueue(1)<<endl;
    cout<<boolalpha<<cq1.enQueue(2)<<endl;
    cout<<boolalpha<<cq1.enQueue(3)<<endl;
    cout<<boolalpha<<cq1.enQueue(4)<<endl;

    cout<<cq1.Rear()<<endl;

    cout<<boolalpha<<cq1.isFull()<<endl;

    cout<<boolalpha<<cq1.deQueue()<<endl;

    cout<<boolalpha<<cq1.enQueue(4)<<endl;

    cout<<cq1.Rear()<<endl; 

    return 0; 
}