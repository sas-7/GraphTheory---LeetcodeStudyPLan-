class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=length(head);
        if(n>size){
            return head;
        }
        int i=1,count=size-n;
        ListNode *temp=head,*curr=NULL;
        if(size==n){
            ListNode* t=head;
            head=head->next;
            delete t;
            return head;
        }
        while(temp!=NULL && i<=count-1){
            temp=temp->next;
            i++;
        }
        curr=temp;
        ListNode*del=curr->next;
        curr->next=del->next;
        delete del;
        return head;
    }
    
    int length(ListNode*head){
        int i=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            i++;
        }
        return i;
    }
};