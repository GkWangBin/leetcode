/*
 * 两数相加，和为定值。求两数的位置
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, length = nums.size();
        vector<int> pos;
        for (int i = 0; i < length-1; ++i)
        {
        	bool flag = false;
        	for (int j = i + 1; j < length; ++j)
        	{
        		if (nums[i] + nums[j] == target)
        		{
        			flag = true;
        			pos.push_back(i);
       			    pos.push_back(j);
        			break;
        		}
        	}
        	if (flag == true)
        	{
       			break;
        	}
        }
        return pos;
    }
};

/**
 * 两个非空链表，每个节点中存储一个非负整数。对应节点中的数值相加放入第三个链表中，向后进位。
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        ListNode *head = l1;
        int flag = 0;
        int num = 0;
        while(l1->next != NULL && l2->next != NULL){
            num = l1->val + l2->val + flag;
            flag = num / 10;
            l1->val = num % 10;
            l2 = l2 -> next;
            l1 = l1 -> next;
        }
        num = l1->val + l2->val + flag;
        flag = num / 10;
        l1->val = num % 10;
        
        if(l1->next != NULL){
            l1->next->val = l1->next->val + flag;
        }
        if(l2 -> next != NULL){
            l1 -> next = l2->next;
            l1->next->val = l1->next->val + flag;
        }
        
        return head;
    }
};
