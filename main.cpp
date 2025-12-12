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
    return 0;
}