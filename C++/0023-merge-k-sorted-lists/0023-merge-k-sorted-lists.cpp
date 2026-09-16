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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(auto i:lists){
            if(i!=nullptr){
                pq.push({i->val,i});
            }
        }

        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        
        while(!pq.empty()){
            auto [val,node]=pq.top();
            pq.pop();

            curr->next=node;
            curr=curr->next;

            if(node->next!=nullptr)
                pq.push({node->next->val,node->next});
          
        }
        return dummy->next;
    }
};