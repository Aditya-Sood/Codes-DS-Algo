/* https://leetcode.com/problems/reverse-nodes-in-k-group */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k <= 1) return head;
        
        ListNode *grp[k], *prev, *curr;
        prev = NULL;
        curr = head;
        
        int i;
        for(i = 0; i < k;)
        {
            if(curr == NULL)
                break;
            
            //else
            grp[i++] = curr;
            curr = curr->next;
        }
        
        if(i < k)   return head;
        else
        {
            grp[0]->next = grp[k-1]->next;
            
            for(int j = 1; j < k; j++)
                grp[j]->next = grp[j-1];
            
            head = grp[k-1];
            prev = grp[0];
            curr = prev->next;
        }
        
        while(curr != NULL)
        {
            for(i = 0; i < k;)
            {
                if(curr == NULL)
                 break;
            
            //else
                grp[i++] = curr;
                curr = curr->next;
            }
        
            if(i < k)   return head;
            else
            {
                grp[0]->next = grp[k-1]->next;
            
                for(int j = 1; j < k; j++)
                    grp[j]->next = grp[j-1];
            
                prev->next = grp[k-1];
                prev = grp[0];
                curr = prev->next;
            }
        }
        
        return head;
        
    }
};