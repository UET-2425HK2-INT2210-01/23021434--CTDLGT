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

class queue {
	node* head = NULL;;
public:
	
	void push()
	{
		int x;
		cin >> x;
		node* newNode = makeNode(x);
		if (check())
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		else {
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}

	}
	void del()
	{
		if (check()) return;
		else {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	bool check()
	{
		if (head == NULL) return true;
		else return false;
	}
	void print()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
	}
};
int main()
{
	int n;
	cin >> n;
	node* head = NULL;
	queue q;
	for (int i = 0; i < n; i++)
	{
		q.push();
	}
	q.del();
	q.del();

	q.print();

	return 0;
}