#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class linked_list {
private:
	node* head;
public:
	linked_list() : head(nullptr);

};
void append_at_end(node* head, int value)
{
	node* new_node = new node();
	new_node->data = value;
	new_node->next = nullptr;
	if (head == nullptr)
		head = new_node;
	return;
}
bool search(node* head, int value)
{
	node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			return true;
		}
		temp = temp->next;
	}

	return false;
}void reverse(node* head)
{
	node* previous = nullptr;
	node* current = head;
	node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = previous;
	}
	head = previous;
}
void print(node* head)
{
	node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data;
		temp = temp->next;

	}
}
int main()
{
	int main() {
		int n;
		cin >> n;
		LinkedList list;

		for (int i = 0; i < n; i++) {
			string command;
			cin >> command;

			if (command == "append") {
				int x;
				cin >> x;
				list.append(x);
			}
			else if (command == "search") {
				int x;
				cin >> x;
				list.search(x);
			}
			else if (command == "reverse") {
				list.reverse();
				list.printList();
			}
		}
		return 0;
	}