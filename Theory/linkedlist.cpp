#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    }
};

void print(node* head) {
	node* cur = head;
	while (cur != NULL) {
		cout << cur -> data << " -> ";
		cur = cur -> next;
	}
	cout << endl;
}

int main(){
    int n;
    cin >> n;
    node* current;
    node* head; 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(i == 0){
            head = new node(a);
            current = head;
        } else{
            current -> next = new node(a);
            current = current -> next;
        }
    }
    print(head);
}