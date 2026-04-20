 //Naive:
//1//Merge list one by one    Time->O(n*k)

//2//Array of Pointers which points to first element of List
//Copare all the pointed elments and choose the min.Include it in the List
//Time->O(n*k)

//3//Join all the lists and apply Sort
//Time->O(nlogn)

//Optimal:check this
//4//Divide and Conqure
//Divide lists into 2 parts
//merge them in bottom up manner
//TIme->O(Nlogk)

//Optimal:
//5//HEaP
//1.Push 1st elments of all k list in min heap
//2.Pop the smallest and add it to list
//3.Update pointer and push new Node(if not NULL)

//Time-> O(k + nlogk)->O(nlogk)
 
//  priority queue + linkedlist
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
    for(int i=0;i<k;i++)
    {
        if(lists[i])pq.push({lists[i]->val,lists[i]});
    }
    ListNode *head=NULL,*curr=NULL;
    while(!pq.empty())
    {
        ListNode *temp=pq.top().second;
        pq.pop();
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
        if(temp->next)pq.push({temp->next->val,temp->next});
    }
    return head;
}