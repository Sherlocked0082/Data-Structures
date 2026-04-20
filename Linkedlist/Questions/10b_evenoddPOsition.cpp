ListNode* oddEvenList(ListNode* head) {
    if(head==NULL)
        return head;
    
    ListNode *odd=head,*even=head->next,*evenStart=head->next;
    
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;        
    return head;
        
}