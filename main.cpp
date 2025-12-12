#include <string>
#include <iostream>
using namespace std;

struct Node 
{
    string customerName;
    string drinkOrdered;
    Node* next;
};

class CoffeeQueue 
{
    private:
        Node* headNode;
        Node* tailNode;
    
    public:
        CoffeeQueue() 
        {
            headNode = tailNode = nullptr;
        }

        void addToQueue(string customerName, string drinkOrdered) 
        {
            Node* newNode = new Node{customerName, drinkOrdered, nullptr};
    
            if (headNode == nullptr) 
            { 
                headNode = newNode;
            } 
            else 
            {
                tailNode->next = newNode;
                tailNode = newNode;
            }
    
            cout << customerName << " entered the line (ordered " << drinkOrdered << ")." << endl;
        }

        void displayList() 
        {
            if (headNode != nullptr) 
            {
                cout << headNode->customerName << endl;
            }

            if (tailNode != nullptr) 
            {
                cout << tailNode->customerName << endl;
            }
           
            cout << endl << "Current queue:" << endl;
            if (headNode == nullptr) 
            {
                cout << "\tempty" << endl;
            }
            else
            {
                Node* curr = headNode;
                while (curr != nullptr) 
                {
                    cout << "\t" << curr->customerName << " - " << curr->drinkOrdered << endl;
                    curr = curr->next;
                }
            }
        }
    };

int main()
{
    srand(time(0));

    CoffeeQueue queue;

    queue.addToQueue("Alice", "Latte");
    queue.addToQueue("Bob", "Cappuccino");
    queue.addToQueue("Charlie", "Espresso");
    
    queue.displayList();

    return 0;
}