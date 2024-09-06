#include<iostream>
using namespace std;

class KQueues{
    public:
    int* arr;
    int* front;
    int* rear;
    int* next;
    int free;
    int k, n; 

    public:
    KQueues(int n,int k){
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for(int i = 0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        free = 0; 
    }
    int enqueue(int data,int qn){
        if(free == -1){
            cout<<"Array is full"<<endl;
            return -1;
        }
        int index = free;
        free = next[index];

        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;
        }
        next[index] = -1;
        rear[qn-1] = index;

        arr[index] = data;

    }
    int dequeue(int qn){
        if(front[qn-1] == -1){
            cout<<"Array is empty"<<endl;
            return -1;
        }
        int index = front[qn-1];
        front[qn-1] = next[index];

        next[index] = free;
        free = index;
        return arr[index];
    }

};

int main(){
    KQueues q(10,3);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(18,1);
    q.enqueue(10,2);
    q.enqueue(50,3);
    q.enqueue(70,2);
    q.enqueue(80,1);
    q.enqueue(90,2);
    q.enqueue(270,1);
    q.enqueue(500,3);

   // cout << q.dequeue(1) << endl;
    //cout << q.dequeue(2) << endl;
    //cout << q.dequeue(1) << endl;
    //cout << q.dequeue(1) << endl;
    //cout << q.dequeue(3) << endl;
    //cout << q.dequeue(2) << endl;

    //cout << q.dequeue(1) << endl;

 return 0;
}