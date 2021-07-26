/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* forward = head;
        Node* backward = head;
        while(forward->next!=NULL)
        {
            forward = forward->next;
        }
        forward->next = backward;
        Node* ptr = head;
        while(k!=1)
        {
            ptr = ptr->next;
            k--;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
        
    }
};
    
