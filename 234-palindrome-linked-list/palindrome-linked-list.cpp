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
    bool isPalindrome(ListNode* head) {
       vector<int>v;
       ListNode* temp=head;
       while(temp!=NULL){
        v.push_back(temp->val);
        temp=temp->next;
       } 
       int i=0;
       int n=v.size();
       int j=n-1;
       if(n==1)return true;
       while(i<j){
        if(v[i]!=v[j])return false;
        i++;
        j--;
       }
       return true;
    }
};