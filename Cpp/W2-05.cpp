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

//recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        //ListNode* rest = head->next;
        //rest->next = head;
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};

 //iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = head;
        ListNode* prev_head = nullptr;
        ListNode* next_head;
        bool first = true;
        if(head!=nullptr)
            next_head = head->next;
        while(true){
            if(head==nullptr){
                break;
            }
            else if(next_head==nullptr){
                head->next = prev_head;
                new_head = head;
                break;
            }
            else{
                prev_head = head;
                head = next_head;
                next_head = head->next;
                head->next = prev_head;
                if(first){
                    first = false;
                    prev_head->next = nullptr;
                }
            }
        }
        return new_head;
    }
};
