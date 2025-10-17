#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(){
        val=0;
        next=NULL;
    }
};

int findMaxSum(int n, Node *head){
        int maxsum=head->val;
        int currsum=head->val;
        Node* current = head->next;
        while(current!=NULL){
            currsum=max(current->val, currsum+current->val);
            maxsum=max(maxsum, currsum);
            current=current->next;
        }
        return maxsum;

}
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}

