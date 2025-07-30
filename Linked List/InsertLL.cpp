#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
    }

    Node(int val, Node* next1){
        data = val;
        next = next1;
    }    
};

Node* convertArrtoLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* temp = new Node(arr[0]);
    Node* start = temp;

    for(int i=1; i<arr.size() ; i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    
    return start;
}

Node* InsertHead(Node* head, int X){
    Node* newNode = new Node(X, head);
    return newNode;
}

Node* InsertAfterTail(Node* head, int X){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(X);
    temp->next = newNode;
    return head;
}

Node* InsertatKth(Node* head, int X, int k){
    if(k==1){
        return InsertHead(head, X);
    }

    Node* temp = head;
    int cnt = 1;
    
    while(cnt < k-1 && temp != nullptr){
        temp = temp->next;
        cnt++;
    }
    if(temp == nullptr) return head;

    Node* newNode = new Node(X, temp->next);
    temp->next = newNode;
    return head;
}

Node* InsertNode(Node* head, int val){

    if(head->data == val){
        return InsertHead(head, val);
    }

    Node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}

void print(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

}

int main(){
    vector<int> arr = {1};
    Node* head = convertArrtoLL(arr);
    
    head = InsertatKth(head, 8, 2);
    print(head);
}
