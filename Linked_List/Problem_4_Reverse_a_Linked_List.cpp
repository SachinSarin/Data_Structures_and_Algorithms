//ITERATIVE APPROACH
struct Node* reverseList(struct Node *head)
    {
        
        struct Node* prev = NULL;
         struct Node* curr = head;
         struct Node* forward = head->next;
        while(curr->next!=NULL)
        {
            curr->next=prev;
            prev = curr;
            curr = forward;
            forward = forward->next;
        }
        
      curr->next= prev;
      return curr;
    }
