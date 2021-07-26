/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    //first find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* ptr = head;
    while(ptr->next!=slow)
    {
        ptr = ptr->next;
    }
    ptr->next = slow->next;
    slow->next = NULL;
    return head;
}
