/*
Linked List contains only three values that is 0 , 1 ,2 and programmer have to sort that linklist
*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int n1 =0;
        int n2=0;
        int n3=0;
        Node* current = head;
        while(current!=NULL)
        {
            if(current->data==0)
            {
                n1++;
            }
            if(current->data==1)
            {
                n2++;
            }
            if(current->data==2)
            {
                n3++;
            }
            current = current->next;
        }
        
        Node* final = new Node(0);
        Node* ptr = final;
        while(n1--)
        {
            ptr->next = new Node(0);
            ptr = ptr->next;
        }
        while(n2--)
        {
            ptr->next = new Node(1);
            ptr = ptr->next;
        }
        while(n3--)
        {
            ptr->next = new Node(2);
            ptr = ptr->next;
        }
        return final->next;
    }
