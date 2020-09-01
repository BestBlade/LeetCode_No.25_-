/*--------------------------------------------------------------------------------------|
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。							|
																						|
k 是一个正整数，它的值小于或等于链表的长度。											|
																						|
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。						|
																						|
 																						|
																						|
示例：																					|
																						|
给你这个链表：1->2->3->4->5																|
																						|
当 k = 2 时，应当返回: 2->1->4->3->5													|
																						|
当 k = 3 时，应当返回: 3->2->1->4->5													|
																						|
来源：力扣（LeetCode）																	|
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group							|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。					|
---------------------------------------------------------------------------------------*/

/*
*
*	执行用时：16 ms, 在所有 C++ 提交中击败了99.69%的用户
*	内存消耗：9 MB, 在所有 C++ 提交中击败了50.78%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* get_k_add(ListNode* l1, int k)
{
	ListNode* ans = l1;

	for (int i = 1; i < k; i++)
	{
		if (ans == NULL)
		{
			return NULL;
		}
		ans = ans->next;
	}
	return ans;
}

pair<ListNode*,ListNode*> exchange_k_Ndoe(ListNode* head, ListNode* tail)
{
	ListNode* prev = tail->next;
	ListNode* p = head;
	while (prev != tail) {
		ListNode* nex = p->next;
		p->next = prev;
		prev = p;
		p = nex;
	}
	return { tail, head };
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
	ListNode* hair = new ListNode(0);
	hair->next = head;
	ListNode* pre = hair;

	while (head) {
		ListNode* tail = pre;
		// 查看剩余部分长度是否大于等于 k
		for (int i = 0; i < k; ++i) 
		{
			tail = tail->next;
			if (!tail) 
			{
				return hair->next;
			}
		}
		ListNode* nex = tail->next;

		pair<ListNode*, ListNode*> result = exchange_k_Ndoe(head, tail);
		head = result.first;
		tail = result.second;


		pre->next = head;
		tail->next = nex;
		pre = tail;
		head = tail->next;
	}

	return hair->next;
}

int main()
{
	ListNode* Head = new ListNode(0);
	ListNode* head = Head;
	Head->next = new ListNode(1);
	Head = Head->next;
	Head->next = new ListNode(2);
	Head = Head->next;
	Head->next = new ListNode(3);
	Head = Head->next;
	Head->next = new ListNode(4);
	Head = Head->next;
	Head->next = new ListNode(5);
	Head = Head->next;
	Head->next = new ListNode(6);
	Head = Head->next;
	Head->next = new ListNode(7);

	head = head->next;
	int k = 3;


	ListNode* khead = get_k_add(head, k);


	//ListNode* ans = reverseKGroup(l1, k);

}