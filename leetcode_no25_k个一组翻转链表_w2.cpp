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
*	执行用时：20 ms, 在所有 C++ 提交中击败了97.98%的用户
*	内存消耗：9 MB, 在所有 C++ 提交中击败了57.51%的用户
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

ListNode* getKAdderss(ListNode* head, int k)
{
	ListNode* khead = head;
	for (int i = 1; i < k; i++)
	{
		if (khead == NULL)
		{
			return NULL;
		}
		khead = khead->next;
	}
	return khead;
}

ListNode* reverseKNode(ListNode* now_head, ListNode* kNode, int k)
{
	ListNode* now_tail = kNode;
	ListNode* l1 = now_head->next;
	if (k == 2)
	{
		now_head->next = now_tail->next;
		now_tail->next = now_head;
		return now_tail;
	}
	if (k == 3)
	{
		now_head->next = now_tail->next;
		l1->next = now_head;
		now_tail->next = l1;
		return now_tail;
	}
	if (k > 3)
	{
		now_head->next = now_tail->next;
		ListNode* l2 = l1->next;
		while (l2 != now_tail->next)
		{
			l1->next = now_head;
			now_head = l1;
			l1 = l2;
			l2 = l2->next;
		}
		now_tail->next = now_head;
	}
	return now_tail;
}

ListNode* reverseKGroup(ListNode* head, int k)
{
	ListNode* kNode = getKAdderss(head, k);
	if (head == NULL || kNode == NULL)
	{
		return NULL;
	}

	ListNode* ans = new ListNode(0);
	ListNode* result = new ListNode(0);
	result = ans;

	while (head && kNode)
	{
		ans->next = reverseKNode(head, kNode, k);
		head = head->next;
		kNode = getKAdderss(head, k);
		ans = getKAdderss(ans->next, k);
	}

	return result->next;
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
	int k = 7;

	ListNode* ans = reverseKGroup(head, k);

}