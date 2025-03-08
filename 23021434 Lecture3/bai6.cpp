#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

node* makeNode(int x)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

class stack {
	node* head = NULL;;
public:
	void push()
	{
		int x;
		cin >> x;
		node* newNode = makeNode(x);
		newNode->next = head;
		head = newNode;
	}
	void pop()
	{
		if (check()) return;
		else {
			node* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	bool check()
	{
		if (head == NULL) return true;
		else return false;
	}
	void print()
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
	}
};



int main()
{
	int n;
	cin >> n;
	node* head = NULL;
	stack st;
	for (int i = 0; i < n; i++)
	{
		st.push();
	}
	st.pop();
	st.pop();

	st.print();

	return 0;
}

