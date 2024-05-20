
#include <iostream>

struct Node {
    int data;
	Node* next;
};

// Fuction to create a new node with the new data
static Node* createNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int main()
{
	Node* head = createNode(1);

	//Node* second = createNode(2);

	//head->next = second:

	int i = 0;
	// Add at the beginning of the list
	/*while (i < 4)
	{
		int input;
		std::cin >> input;

		Node* newNode = createNode(input);
		newNode->next = head;
		head = newNode;

		i++;
	}*/

	// Add at the end of the list
	while (i < 4)
	{
		int input;
		std::cin >> input;

		Node* newNode = createNode(input);
		Node* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;

		i++;
	}

	int index = -1;
	bool found = false;
	Node* temp = head;
	while (temp->next != NULL)
	{
		if (temp->data == 7) {
			found = true;
			index++;
			break;
		}

		temp = temp->next; 
		index++;
	}

	if (temp->data == 7)
	{
		found = true;
		index++;
	}

	if (found)
	{
		std::cout << "Found at index: "<< index + 1<< std::endl;
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}

	std::cout << head->data << " " << head->next->data << std::endl;
	//std::cout << "Index of 3 is " << index + 1 << std::endl;
}

