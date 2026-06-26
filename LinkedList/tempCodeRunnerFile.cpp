    temp = temp->next;
  }

  temp = head2;
  while(temp != NULL){
    if(mp.find(temp) != mp.end()){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}


Node* intersectionPresentOptimal(Node* head1, Node*  head2){
  if(head1 == NULL || head2 == NULL) return NULL;
  Node* temp1 = head1;
  Node* temp2 = head2;

  while(temp1 != temp2){
    temp1 = temp1->next;
    temp2 = temp2->next;

    if(temp1 == temp2) return temp1;

    if(temp1 == NULL) temp1 = head2;
    if(temp2 == NULL) temp2 = head1;
  }
  return temp1;
}

int main() {
    vector<int> arr1 = {4, 1, 8, 4, 5};
    vector<int> arr2 = {5, 6, 1};

    Node* head1 = convertArr2LL(arr1);
    Node* head2 = convertArr2LL(arr2);

    // Find node with value 8 in list1
    Node* temp = head1;
    while(temp->data != 8) {
        temp = temp->next;
    }

    // Attach end of list2 to node 8
    Node* tail = head2;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;

    Node* ans = intersectionPresentOptimal(head