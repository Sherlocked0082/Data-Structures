 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*curr=NULL;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            
            int total=x+y+carry;
            carry=total/10;
            total=total%10;
            
            ListNode *temp=new ListNode(total);
            if(head==NULL)
            {
                head=temp;
                curr=temp;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry>0)
        {
            ListNode *temp=new ListNode(carry);
            curr->next=temp;
        }
        return head;
    }