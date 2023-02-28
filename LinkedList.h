#include <string>
#include <stdexcept>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template <typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node
    {
        T data;
        Node *nextNode;
    };
    Node *head = NULL;

public:
    LinkedList(void){};
    virtual ~LinkedList(void)
    {
        clear();
    };

    /*
    insertHead

    A node with the given value should be inserted at the beginning of the list.

    Do not allow duplicate values in the list.
    */
    void insertHead(T value)
    {
        cout << "Entering insertHead function." << endl;
        if (find(value))
        {
            cout << "Duplicate values are not allowed." << endl;
        }
        else if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->nextNode = NULL;
        }
        else
        {
            Node *temporary = head;
            head = new Node;
            head->data = value;
            head->nextNode = temporary;

            temporary = head;
            while (temporary->nextNode != NULL)
            {
                cout << "Data in this Node: " << temporary->data << endl;
                temporary = temporary->nextNode;
            }
        }
    };

    /*
    insertTail

    A node with the given value should be inserted at the end of the list.

    Do not allow duplicate values in the list.
    */
    void insertTail(T value)
    {
        cout << "Entering insertTail function." << endl;
        if (find(value))
        {
            cout << "Duplicate values are not allowed." << endl;
        }
        else if (head == NULL)
        {
            insertHead(value);
        }
        else
        {
            Node *tracker = head;
            while (tracker->nextNode != NULL)
            {
                tracker = tracker->nextNode;
            }

            tracker->nextNode = new Node;
            tracker = tracker->nextNode;
            tracker->data = value;
            tracker->nextNode = NULL;
        }
    };

    /*
    insertAfter

    A node with the given value should be inserted immediately after the
    node whose value is equal to insertionNode.

    A node should only be added if the node whose value is equal to
    insertionNode is in the list. Do not allow duplicate values in the list.
    */
    void insertAfter(T value, T insertionNode)
    {
        cout << "Entering insertAfter function." << endl;
        if (find(value))
        {
            cout << "Duplicate values are not allowed." << endl;
        }
        else if (!find(insertionNode))
        {
            cout << "Insertion node does not exist." << endl;
        }
        else
        {
            Node *tracker = head;
            while (tracker->data != insertionNode)
            {
                tracker = tracker->nextNode;
            }
            Node *insertingNode = new Node;
            insertingNode->data = value;
            insertingNode->nextNode = tracker->nextNode;
            tracker->nextNode = insertingNode;
        }
    };

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value)
    {
        cout << "Entering remove function." << endl;
        if (!find(value))
        {
            cout << "The value does not exist in the list." << endl;
        }
        else if (value == at(0))
        {
            Node *temporary = head;
            head = head->nextNode;
            delete temporary;
        }
        else
        {
            Node *temporary = head;
            while (temporary->nextNode->data != value)
            {
                temporary = temporary->nextNode;
            }
            Node *targetNode = temporary->nextNode;
            temporary->nextNode = targetNode->nextNode;
            delete targetNode;
        }
    };

    /*
    clear

    Remove all nodes from the list.
    */
    void clear()
    {
        while (head != NULL)
        {
            remove(head->data);
        }
    };

    /*
    at

    Returns the value of the node at the given index. The list begins at
    index 0.

    If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index)
    {
        cout << "Entering at function." << endl;
        if ((index < 0) || (index >= size()))
        {
            throw out_of_range("out of range");
        }
        Node *tracker = head;
        for (int i = 0; i <= index; ++i)
        {
            if (i == index)
            {
                return tracker->data;
            }
            tracker = tracker->nextNode;
        }
        cout << "Problem with at function" << endl;
        return head->data;
    };

    /*
    size

    Returns the number of nodes in the list.
    */
    int size()
    {
        cout << "Entering size function." << endl;
        if (head == NULL)
        {
            return 0;
        }

        int counter = 0;
        Node *tracker = head;
        while (tracker != NULL)
        {
            counter += 1;
            tracker = tracker->nextNode;
        }
        return counter;
    };

    /*
    toString

    Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
    There should be no trailing space at the end of the string

    For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
    "1 2 3 4 5"
    */
    string toString()
    {
        stringstream myList;
        Node *tracker = head;
        if (tracker == NULL)
        {
            return "";
        }
        else
        {
            while (tracker != NULL)
            {
                myList << tracker->data;
                cout << "Data going into stringstream is: " << tracker->data << endl;
                if (tracker->nextNode != NULL)
                {
                    myList << " ";
                }
                tracker = tracker->nextNode;
            }
            return myList.str();
        }
    };

    bool find(T value)
    {
        cout << "Entering find function." << endl;
        Node *tracker = head;
        while (tracker != NULL)
        {
            if (tracker->data == value)
            {
                return true;
            }
            tracker = tracker->nextNode;
        }
        return false;
    }
};