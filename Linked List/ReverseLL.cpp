#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* ReverseList(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* prev  = nullptr;
    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main(){
    vector<int> arr = {8, 3, 4, 5};
    
}
