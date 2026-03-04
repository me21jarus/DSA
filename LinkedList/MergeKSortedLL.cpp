/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=NULL){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        return dummy->next;
    }
    ListNode* mergeKLL(vector<ListNode*>& lists,int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start+1==end){
            return mergeTwoLists(lists[start],lists[end]);
        }
        int mid=start+(end-start)/2;
        ListNode* left=mergeKLL(lists,start,mid);
        ListNode* right=mergeKLL(lists,mid+1,end);
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        return mergeKLL(lists,0,lists.size()-1);
    }
};