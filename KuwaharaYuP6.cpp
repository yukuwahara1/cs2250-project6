//============================================================================
// Name        : KuwaharaYuP6.cpp
// Author      : Yu Kuwahara
//============================================================================
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//===========================CLASS PROTPTYPE==================================
class NumberList
{
private:

	struct ListNode // declare a structure for the linked list
	{
		int data; // the value in the node
		ListNode *next; // a pointer of data type - ListNode (structure), points to the next node
	};

	ListNode *head; // a pointer of data type - ListNode (structure), points to the head node

public:

	NumberList() // default constructor, FROM THE TEXTBOOK AND TECHNICALLY NOT NEEDED IN THIS PROJECT
	{
		head = nullptr; // initialize the pointer, head
	}

	NumberList(int value) // constructor taking value, FROM THE TEXTBOOK AND TECHNICALLY NOT NEEDED IN THIS PROJECT
	{
		head = new ListNode; // ListNode (structure) is dynamically memory allocated as head
		head->data = value; // value is stored as data accessed by head
		head->next = nullptr; // next accessed by head is initialized
	}

	// destructor
	~NumberList() 
	{
		// keep running the program until the last nodePtr is a null pointer
		ListNode* nodePtr = head;
		while (nodePtr != nullptr) 
		{
			nodePtr = head->next; // next accessed by head is stored as nodePtr
			delete head; // always delete dynamic memory allocated objects
			head = nodePtr;
		}
		nodePtr = nullptr;
	}

	// Linkedlist operations from the textbook 
	void appendNode(int value);
	void insertNode(int value);
	void deleteNode(int value);
	void displayList() const;

	// Linkedlist operations required on this assignment
	void insertAtPosition(int pos, int value);
	void deleteAtPosition(int pos);
	int search(int key);
	void printMember(int pos);

};
//==============================MAIN FUNCTION=================================
int main()
{
	bool isRunning = true; // change to false when the user wants to quit the program
	int choice = -1;

	// display menu #1
	while (isRunning)
	{
		cout << "Welcome to the linkedlist program!\n\n";
		cout << "Please select a choice from below: \n";
		cout << "1) Create an empty linkedlist\n"
			<< "2) Create a linkedlist with values\n"
			<< "3) Quit\n\n";
		cout << "Choice: ";
		cin >> choice;

		cout << endl;

		// menu #1
		switch (choice)
		{

		case 1: // create an empty linkedlist
		{
			NumberList constructedList;
			system("CLS"); // clear the console screen
			cout << "Empty linkedlist was constructed!\n";
			cout << endl;

			// display menu #2
			while (isRunning)
			{
				choice = 0;
				cout << "Please select a choice from below: \n";
				cout << "1) Insert an element to a position in the list\n"
					<< "2) Insert element(s) into the list\n"
					<< "3) Append an element at the end\n"
					<< "4) Delete an element at a position\n"
					<< "5) Delete an element by value\n"
					<< "6) Print a member at a position\n"
					<< "7) Search for a value to get its position\n"
					<< "8) Print the current LinkedList\n"
					<< "9) Quit\n\n";
				cout << "Choice: ";
				cin >> choice;

				switch (choice)
				{

				case 1: // insert an element to a position in the list
				{
					choice = 0;
					int value = -1;
					int position = -1;

					system("CLS"); // clear the console screen

					cout << "Enter a value of node to insert: ";
					cin >> value;
					cin.ignore(1000, '\n'); // clear the input buffer 

					cout << "Enter a position to insert: ";
					cin >> position;

					constructedList.insertAtPosition(position, value);
					system("CLS"); // clear the console screen

					// display which value was inserted at which position
					if (constructedList.search(value) >= 0)
					{
						cout << "Element with value " << value << " was inserted to position " << position << "\n";
					}

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 2: // insert element(s) into the list
				{
					choice = 0;
					system("CLS"); // clear the console screen

					cout << "Enter the value(s) of node(s) (if there is more than one value please separate by space: \n";
					cout << "Value: ";

					string values; // string to store getline input
					string value; // value tokens
					int convertedValues = 0; // stringstream will convert the values tokens into ints
					size_t pos = 0; // get set to the length of position

					cin.ignore(1000, '\n'); // clear the input buffer
					getline(cin, values);
					values += " "; // append a space to the end of value string 

					// set pos to size of current values token until the end of the string is reached loop
					while ((pos = values.find(" ")) != string::npos)
					{
						value = values.substr(0, pos); // set the token
						stringstream converted(value); // need to convert string to int
						converted >> convertedValues; // the conversion
						if (pos > 0) // if pos is 0 then current token is just a space to prevent from duplicated insertion
							constructedList.insertNode(convertedValues); // insert converted token into the list
						values.erase(0, pos + 1); // erase current token from value string to parse for next token
					}

					system("CLS"); // clear the console screen

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 3: // append an element at the end
				{
					choice = 0;
					system("CLS");

					int value = -1;

					cout << "Enter a value of node to append at the end of the list: ";
					cin.ignore(1000, '\n');
					cin >> value;

					constructedList.appendNode(value);

					system("CLS"); // clear the console screen

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 4: // delete an element at a position
				{
					choice = 0;
					system("CLS"); // clear the console screen

					int position = -1;

					cout << "Enter a position of node to delete: ";
					cin.ignore(1000, '\n');
					cin >> position;

					system("CLS"); // clear the console screen
					constructedList.deleteAtPosition(position);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 5: // Delete an element by value
				{
					choice = 0;
					system("CLS"); // clear the console screen

					int value = -1;

					cout << "Enter a value of node to delete: ";
					cin.ignore(1000, '\n');
					cin >> value;

					system("CLS"); // clear the console screen
					constructedList.deleteNode(value);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 6: // print a member at a position
				{
					choice = 0;
					system("CLS"); // clear the console screen

					int position = -1;

					cout << "Enter a position to print: ";
					cin.ignore(1000, '\n');
					cin >> position;

					system("CLS"); // clear the console screen
					constructedList.printMember(position);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 7: // search for a value and show its position
				{
					choice = 0;
					system("CLS"); // clear the console screen

					int searchValue = 0;

					cout << "Enter a value of node to search for: ";
					cin.ignore(1000, '\n');
					cin >> searchValue;

					system("CLS"); // clear the console screen

					// display the result
					if (constructedList.search(searchValue) != -1)
					{
						cout << "The value " << searchValue << " is at position " << constructedList.search(searchValue) << endl;
					}

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 8: // print the current list
				{
					choice = 0;
					system("CLS"); // clear the console screen

					cout << "The current list is: ";

					constructedList.displayList();
					cout << endl << endl;
					
					break;
				}

				case 9: // quit 
				{
					choice = 0;
					system("CLS"); // clear the console screen

					cout << "Thank you for using the linkedlist program!\n";

					isRunning = false;

					break;
				}

				default:
				{
					choice = 0;

					system("CLS"); // clear the console screen
					cout << "Please select a valid option!";
					cout << endl << endl;

					break;
				}
				}
			}

			break;
		} // the end of menu #2 for making an empty linkedlist

		case 2: // create a linkedlist with value (sorted)
		{
			choice = 0;
			system("CLS");

			NumberList constructedList;

			cout << "Enter your value(s) (if there is more than one please separate them by space): \n";
			cout << "Value: ";

			string value; // string to store getline input
			string values; // values tokens
			int convertedValues = 0; // stringstream will convert the values tokens into ints.
			size_t pos = 0; // get set to the length of a value

			cin.ignore(1000, '\n'); // clear the input buffer
			getline(cin, value);
			value += " "; // append a space to the end of values string

			// set pos to size of current values token until the end of the string is reached loop
			while ((pos = value.find(" ")) != string::npos)
			{
				values = value.substr(0, pos); // set the token.
				stringstream converted(values); // need to convert string to int
				converted >> convertedValues; // the conversion

				if (pos > 0) // if pos is 0 then current token is just a space to prevent from duplicated insertion
				{
					constructedList.insertNode(convertedValues); // insert converted token into the list
				}

				value.erase(0, pos + 1); // erase current token from data string to parse for next token 
			}

			system("CLS");

			cout << "Linkedlist was created by you!\n";

			constructedList.displayList();
			cout << endl << endl;
			
			while (isRunning)
			{
				choice = 0;
				cout << "Please select a choice from below: \n";
				cout << "1) Insert an element to a position in the list\n"
					<< "2) Insert element(s) into the list\n"
					<< "3) Append an element at the end\n"
					<< "4) Delete an element at a position\n"
					<< "5) Delete an element by value\n"
					<< "6) Print a member at a position\n"
					<< "7) Search for a value to get its position\n"
					<< "8) Print the current LinkedList\n"
					<< "9) Quit\n\n";
				cout << "Choice: ";
				cin >> choice;

				switch (choice)
				{

				case 1: // insert an element to a position in the list
				{
					choice = 0;
					int value = -1;
					int position = -1;

					system("CLS");

					cout << "Enter a value to insert: ";
					cin >> value;
					cin.ignore(1000, '\n'); // clear the input buffer 
					cout << "Enter a position to insert: ";
					cin >> position;

					constructedList.insertAtPosition(position, value);

					system("CLS");

					if (constructedList.search(value) >= 0)
					{
						cout << "Element with value " << value << " was inserted to position " << position << "\n";
					}

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 2: // insert element(s) into the list
				{
					choice = 0;
					system("CLS");

					cout << "Enter the value(s) (if there is more than one value please separate by space: \n";
					cout << "Value: ";

					string values; // string to store getline input
					string value; // value tokens
					int convertedValues = 0; // stringstream will convert the values tokens into ints
					size_t pos = 0; // get set to the length of a 
					cin.ignore(1000, '\n'); // clear the input buffer
					getline(cin, values);
					values += " "; // append a space to the end of value string 

					// set pos to size of current values token until the end of the string is reached loop
					while ((pos = values.find(" ")) != string::npos)
					{
						value = values.substr(0, pos); // set the token
						stringstream converted(value); // need to convert string to int
						converted >> convertedValues; // the conversion
						if (pos > 0) //if pos is 0 then current token is just a space to prevent from duplicated insertion
							constructedList.insertNode(convertedValues); // insert converted token into the list
						values.erase(0, pos + 1); // erase current token from value string to parse for next token
					}

					system("CLS");
					cout << "Value was entered into list!\n\n";

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 3: // append an element at the end
				{
					choice = 0;
					system("CLS");

					int value = -1;

					cout << "Enter a value to append at the end of the list: ";
					cin.ignore(1000, '\n');
					cin >> value;

					constructedList.appendNode(value);

					system("CLS");

					cout << value << " was appended at the end of the list!\n";

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 4: // delete an element at a position
				{
					choice = 0;
					system("CLS");

					int position = -1;

					cout << "Enter a position to delete: ";
					cin.ignore(1000, '\n');
					cin >> position;

					system("CLS");

					constructedList.deleteAtPosition(position);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 5: // delete an element by value
				{
					choice = 0;
					system("CLS");

					int value = -1;

					cout << "Enter a value to delete: ";
					cin.ignore(1000, '\n');
					cin >> value;

					system("CLS");

					constructedList.deleteNode(value);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 6: // print a member at a position
				{
					choice = 0;
					system("CLS");

					int position = -1;

					cout << "Enter a position to print: ";
					cin.ignore(1000, '\n');
					cin >> position;

					system("CLS");

					constructedList.printMember(position);

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 7: // search for a value and show its position
				{
					choice = 0;
					system("CLS");

					int searchValue = 0;

					cout << "Enter a value to search for: ";
					cin.ignore(1000, '\n');
					cin >> searchValue;

					system("CLS");

					if (constructedList.search(searchValue) != -1)
					{
						cout << "The value " << searchValue << " is at position " << constructedList.search(searchValue) << endl;
					}

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 8: // print the current list
				{
					choice = 0;
					system("CLS");

					constructedList.displayList();
					cout << endl << endl;

					break;
				}

				case 9: // quit 
				{
					choice = 0;
					system("CLS");

					cout << "Thank you for using the linkedlist program!\n";
					isRunning = false;

					break;
				}

				default:
				{
					choice = 0;
					system("CLS");

					cout << "Please select a valid option!";
					cout << endl << endl;

					break;
				}

				}
			}
			break;

		} // the end of menu #2 for making a sorted linked list

		case 3: // quit
		{
			system("CLS");
			cout << "Thank you for using the linkedlist program!\n";
			isRunning = false;
			break;
		}

		default:
			system("CLS");
			cout << "Please select a valid option!";
			cout << endl << endl;

			cin.ignore(1000, '\n');
			break;

		} // the end of menu #1

	} // the end of while loop to keep using the program

	return 0;

} // the end of the main function 

  //======================DEFAULT CLASS MEMBER FUNCTION DEFINITION========================
  // append node based on the value of node
void NumberList::appendNode(int value)
{
	ListNode *newNode; // to point a new node
	newNode = nullptr; // always initialize a pointer

	ListNode *nodePtr; // to move through the list
	nodePtr = nullptr; // always initialize a pointer

	// allocate a new list of nodes and store data there
	newNode = new ListNode; // the dynamic memory allocated structure ListNode is now called newNode
	newNode->data = value; // value is stored as data accessed by newNode
	newNode->next = nullptr; // next accessed by newNode is initialized

	// if there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
	}
	else // otherwise insert a newNode at end
	{
		// initialize nodePtr to head of list
		nodePtr = head;

		// find the last node in the list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		// insert newNode as the last node
		nodePtr->next = newNode;
	}

}

// insert node based on the value of node
void NumberList::insertNode(int value)
{
	ListNode *newNode; // to point a new node
	newNode = nullptr; // always initialize a pointer

	ListNode *nodePtr; // to travel the list
	nodePtr = nullptr; // always initialize a pointer

	ListNode *previousNode; // the previous node
	previousNode = nullptr; // always initialize a pointer

	// allocate a new list of nodes and store data there
	newNode = new ListNode; // the dynamic memory allocated structure ListNode is now called newNode
	newNode->data = value; // value is stored as data accessed by newNode

	// if there is no node in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // otherwise insert newNode
	{
		// position nodePtr at the head of list
		nodePtr = head;

		// skip all nodes whose value is less than data
		while (nodePtr != nullptr && nodePtr->data < value)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// if the new node is to be the first in the list
		// insert it before all other nodes
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // otherwise insert after the previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

// delete node based on the value of node
void NumberList::deleteNode(int value)
{
	ListNode *nodePtr; // to transverse the list
	nodePtr = nullptr; // always initialize a pointer

	ListNode *previousNode; // to point to the previous 
	previousNode = nullptr; // always initialize a pointer

	// if the list is empty, do nothing
	if (!head)
	{
		return;
	}

	// determine if the first node is the one
	if (head->data == value)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// initialize nodePtr to head of list
		nodePtr = head;

		// skip all the nodes whose value member is
		// not equal to data
		while (nodePtr != nullptr && nodePtr->data != value)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		// show an error message in case a number which is not on the list was tried to delete
		else
		{
			cout << "Please type a valid number on the list!" << endl;
		}
	}
}

// display the linked list
void NumberList::displayList() const
{
	ListNode *nodePtr; // to transverse the list
	nodePtr = nullptr; // initialize the nodePtr

	// iterate through the linked list and display each node
	cout << "The current linked list is: ";

	nodePtr = head;
	cout << nodePtr->data << " ";

	while (nodePtr->next != nullptr)
	{
		nodePtr = nodePtr->next;
		cout << nodePtr->data << " ";
	}

}
//======================ASSIGNMENT CLASS MEMBER FUNCTION DEFINITION========================
// insert node based on its position
void NumberList::insertAtPosition(int pos, int value)
{
	// show an error message if its position is negative 
	if (pos < 0)
	{
		cout << "\nPlease do not insert a node at a negative position!\n";
		return;
	}

	// show an error message if the list is empty and the position is not 0
	if (head == nullptr && pos != 0)
	{
		cout << "\nSorry, the list is empty and you need to insert a node at a position zero!\n";
		return;
	}

	// create a new node to insert
	ListNode* newNode; // to point a new node
	newNode = nullptr; // always initialize a pointer

	// allocate a new list of nodes and store data there
	newNode = new ListNode; // the dynamic memory allocated structure ListNode is now called newNode
	newNode->data = value; // value is stored as data accessed by newNode
	newNode->next = nullptr; // initialize next to nullptr whose value will be set once the node is inserted

	// declare iterators
	ListNode* nodePtr; // to travel the list
	nodePtr = nullptr; // always initialize a pointer
	nodePtr = head; // to travel the list

	ListNode* previousNode; // the previous node
	previousNode = nullptr; // always initialize a pointer

	// replace the head if the position is 0
	if (pos == 0)
	{
		head = newNode;
		newNode->next = nodePtr;
		newNode = nullptr;
		nodePtr = nullptr;
		return;
	}

	// go to its position in the list

	int currentPosition = 0; // declare a counter

	// iterate through the list until the selected position or the end of the list is reached
	while (nodePtr->next != nullptr && currentPosition < pos)
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
		++currentPosition;
	}

	// insert at the back of the list
	// if the end of the list was reached and the position is 1 more than the current position
	if (nodePtr->next == nullptr && pos == currentPosition + 1)
	{
		nodePtr->next = newNode;
		nodePtr = nullptr;
		previousNode = nullptr;
		newNode = nullptr;
		return;
	}

	// show an error message
	// if the end of the list was reached and the selected position was greater than 1 beyond the size of the LL
	else if (nodePtr->next == nullptr && pos > currentPosition + 1)
	{
		cout << "Please select a valid position to insert!\n";
		delete newNode;
		newNode = nullptr;
		nodePtr = nullptr;
		previousNode = nullptr;
		return;
	}

	// insert the newNode behind the nodePtr
	else
	{
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}

}

// delete the node at its position
void NumberList::deleteAtPosition(int pos)
{
	// declare iterators
	ListNode* nodePtr = head;
	ListNode* previousNode = nullptr;
	int currentPosition = 0;

	// show an error message if the user entered a negative position
	if (pos < 0)
	{
		cout << "Sorry, the position of node cannot be negative!\n";
		return;
	}

	// delete the head if the position is 0 and the list is not empty
	if (pos == 0 && head != nullptr)
	{
		head = nodePtr->next;
		delete nodePtr;
		nodePtr = nullptr;
		return;
	}

	// show an error message if the list is empty
	else if (pos >= 0 && head == nullptr)
	{
		cout << "Sorry, the list is empty!\n";
		nodePtr = nullptr;
		return;
	}

	// iterate through the list to the selected position
	while (nodePtr->next != nullptr && currentPosition != pos)
	{
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
		++currentPosition;
	}

	// show an error message if selected position is too large
	if (nodePtr->next == nullptr && pos > currentPosition)
	{
		cout << "Sorry, the selected position is too large!\n";
		return;
	}

	// delete the node at the position if not the last element is in the list
	else if (nodePtr->next != nullptr && pos == currentPosition)
	{
		previousNode->next = nodePtr->next;
		delete nodePtr;
		nodePtr = nullptr;
		previousNode = nullptr;
		return;
	}

	// delete the last node
	else
	{
		previousNode->next = nullptr;
		delete nodePtr;
		nodePtr = nullptr;
		previousNode = nullptr;
		return;
	}

}

// search a node by keyword
int NumberList::search(int key)
{
	int pos = 0;
	ListNode *nodePtr = head;

	// show an error message if the list is empty
	if (head == nullptr)
	{
		cout << "Sorry, this list is empty!\n";
		return -1;
	}

	// traverse the list until the key is found or the end of the list
	while (nodePtr->data != key && nodePtr->next != nullptr)
	{
		nodePtr = nodePtr->next;
		++pos;
	}

	// return pos if the key is found
	if (nodePtr->data == key)
	{
		return pos;
	}

	// show an error message if the key is not found
	else {
		cout << "Sorry, the key was not found!\n";
		return -1;
	}
}

void NumberList::printMember(int pos)
{
	// show an error message if the position is negative
	if (pos < 0)
	{
		cout << "Please choose a valid position!\n";
		return;
	}

	// create a node pointer to iterate through the list
	ListNode* nodePtr = head;

	// iterate through the list until the position is reached or until the end of the list
	for (int i = 0; i < pos && nodePtr != nullptr; ++i)
	{
		nodePtr = nodePtr->next;
	}

	// print the particular element 
	if (nodePtr != nullptr)
	{
		cout << "The value at position " << pos << " is " << nodePtr->data << endl;
	}

	// show an error message if the position is not larger than the length of the list)
	else
	{
		cout << "Please choose a valid position!\n";
	}

	nodePtr = nullptr;

	return;
}