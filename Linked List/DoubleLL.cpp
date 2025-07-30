#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i=1; i< arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node* mover = head;

    while(mover != nullptr){
        // Node* temp = new node(arr[i]);
        cout<< mover->data << " ";
        mover = mover->next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    Node* tail = head;
    if(tail == NULL || tail->next == NULL) return NULL;
    
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head, int k){
    if (head == NULL){
        return NULL;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }

    Node* prev = temp->prev;
    Node* front = temp->next;
    
    if(prev == NULL && front == NULL) {
        return NULL;
    }

    else if(prev == NULL) {
        return deleteHead(head);
    }

    else if(front == NULL) {
        return deleteTail(head);
    }
     
    prev->next = temp->next;
    front->prev = prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// void deleteNode(Node* temp, int val){
//     Node* prev = temp->prev;
//     Node* front = temp->next;

//     if(front == NULL){
//         prev->next = nullptr;
//         temp->prev = nullptr;
//         delete temp;
//         return;
//     }
//     prev->next = front;
//     front->prev = prev;
//     temp->prev = nullptr;
//     temp->next = nullptr;
//     delete temp;
// }
Node* deleteNode(Node* head, int val){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;

    while(temp->data != val){
        temp = temp->next;
    }
    if (temp == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        return head;
    }
    Node* prev = temp->prev;
    Node* front = temp->next;
    front->prev = prev;
    prev->next = front;
    temp->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

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
    return prev;
}

int main(){
    vector<int> arr = {6, 3, 4};
    Node* head = convertArr2DLL(arr);
    // cout << head->data;
    head = deleteNode(head, 3);
    print(head);
    return 0;
}
