/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        if(head==NULL)
        {
            head = new Node(data);
        }
        if(data<=head->data)
        {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            return head;
        }
        Node* curr = head->next;
        Node* prev = head;
        
        while(curr!=NULL)
        {
            if(curr->data>data)
            {
                Node* temp = new Node(data);
                temp->next=curr;
                prev->next=temp;
                return head;
            }
            prev = curr;
            curr= curr->next;
            
        }
        prev->next=new Node(data);
        return head;
    }
};
