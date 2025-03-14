#include<iostream>
#include<string>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
	int priority;
};

node* makeNode(int x, int y)
{
	node* newNode = new node();
	newNode->data = x;
	newNode->priority = y;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

class queue {
	node* head = NULL;
public:
	bool check()
	{
		if (head == NULL) return true;
		else return false;
	}

	void enqueue()
	{
		int x, y;
		cin >> x >> y;
		node* newNode = makeNode(x, y);
		if (check())
		{
			head = newNode;
			return;
		}
		if (newNode->priority > head->priority)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}
		node* tmp = head;
		while (tmp->next != NULL && newNode->priority < tmp->priority)
		{
			tmp = tmp->next;
		}
		if (tmp->next == NULL)
		{
			tmp->next = newNode;
			newNode->prev = tmp;
			return;
		}
		newNode->next = tmp->next;
		tmp->next->prev = newNode;
		newNode->prev = tmp;
		tmp->next = newNode;
	}

	void print()
	{
		node* tmp = head;
		while (tmp != NULL)
		{
			cout << '(' << tmp->data << ", " << tmp->priority << "); ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	void dequeue()
	{
		if (head == NULL) return;
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}
};

int main()
{
	int n;
	cin >> n;
	int x, y;
	node* head = NULL;
	queue q;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "enqueue")
		{
			q.enqueue();
		}
		else if (str == "dequeue")
		{
			q.dequeue();
		}
	}
	q.print();

	return 0;
}