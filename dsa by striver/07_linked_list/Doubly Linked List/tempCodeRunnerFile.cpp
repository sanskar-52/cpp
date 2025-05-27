Node* arr2DLL(vector<int> &arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* walker = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,walker);
        walker->next = temp;
        walker = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {12,2,4,7,13,15,17,19,21,23,27};
    //now i have to make a Doubly linked list of this array.

}