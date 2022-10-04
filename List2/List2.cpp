// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node
{
	int data;
	node* next;
	node* prev;
};

node* init(int a)
{
	node* p = new node;
	p->data = a;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}

node* addNode(node* nd, int number)
{
	node* tmp, * p;
	tmp = new node;
	p = nd->next;
	nd->next = tmp;
	tmp->data = number;
	tmp->next = p;
	tmp->prev = nd;
	if (p != nullptr)
		p->prev = tmp;
	return tmp;
}

node* deleteNode(node* nd)
{
	node* prev,*next;
	prev = nd->prev;
	next = nd->next;
	if (prev != nullptr)
		prev->next = next;
	if (next != nullptr)
		next->prev = prev;
	delete nd;
	return prev;
}

//node* deleteNode(int data, node* head);

node* deleteHead(node* head)
{
	node* p = head->next;
	p->prev = nullptr;
	delete head;
	return p;
}

void printList(node* head)
{
	node* p = head;
	while (p != nullptr)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

void printListReverse(node* head)
{
	node* p = head;
	while (p->next != nullptr)
		p = p->next;
	while (p != nullptr)
	{
		std::cout << p->data << " ";
		p = p->prev;
	}
	std::cout << std::endl;
}

node* swap(node* nd1, node* nd2, node* head)
{
	node* prev1, * prev2, * next1, * next2;
	prev1 = nd1->prev;
	prev2 = nd2->prev;
	next1 = nd1->next;
	next2 = nd2->next;
	if (nd2 == next1)
	{
		nd2->next = nd1;
		nd2->prev = prev1;
		nd1->next = next2;
		nd1->prev = nd2;
		if (nd1 != head)
			prev1->next = nd2;
		if (nd2 != head)
			next2->prev = nd1;
	}
	else
	{
		if (nd1 == next2)
		{
			nd1->next = nd2;
			nd1->prev = prev2;
			nd2->next = next1;
			nd2->prev = nd1;
			if (nd2 != head)
				prev2->next = nd1;
			if (nd1 != head)
				next1->prev = nd2;
		}
		else
		{
			nd1->next = next2;
			nd2->next = next1;
			if (nd1 != head)
				prev1->next = nd2;
			if (nd2 != head)
				prev2->next = nd1;
			if (nd2 != head)
				next2->prev = nd1;
			if (nd1 != head)
				next1->prev = nd2;
			nd1->prev = prev2;
			nd2->prev = prev1;
			
		}
	}
	if (nd1 == head)
		return nd2;
	if (nd2 == head)
		return nd1;
	return	head;
}

int main()
{
	node* head = init(1);
	addNode(head, 2);
	addNode(head, 3);
	node* p1 = addNode(head, 4);
	printList(head);
	deleteNode(p1);
	printList(head);
	head = deleteHead(head);
	printList(head);
	node* p2 = addNode(head, 5);
	node* p4 = addNode(head, 6);
	node* p3 = addNode(head, 7);
	printList(head);
	head = swap(p2, p3, head);
	printList(head);
	printListReverse(head);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
