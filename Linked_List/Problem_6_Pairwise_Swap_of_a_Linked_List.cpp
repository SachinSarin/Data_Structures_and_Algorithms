/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
     Node* swap(struct Node* next1 , struct Node* next2)
    {
        next1->next  = next2->next;
        next2->next = next1;
        return next2;

    }
    Node* pairWiseSwap(struct Node* head) 
    {
        struct Node* start = new Node(0);
        start->next = head;

         struct    Node* curr = start;

        while(curr->next!=NULL&&curr->next->next!=NULL)
        {
        curr->next = swap(curr->next ,curr->next->next);
        curr = curr->next->next;
        }
        return start->next;
    }
};
