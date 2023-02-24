#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}
    void create(int arr[], int n)
    {
        head = new Node(arr[0]);
        Node *last = head;
        for (int i = 1; i < n; i++)
        {
            Node *newNode = new Node(arr[i]);
            last->next = newNode;
            last = newNode;
        }
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[] = {3, 6, 2, 9, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    LinkedList myList;
    myList.create(arr, n);
    myList.display();
    return 0;
}
