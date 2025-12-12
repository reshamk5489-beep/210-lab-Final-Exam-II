#include <string>
#include <iostream>
using namespace std;

const int MAX_CUSTOMER_NAMES = 10;
const int MAX_DRINKS_ORDERED = 7;

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

        bool isQueueEmpty() 
        {
            return headNode == nullptr;
        }

        void addToQueue(string customerName, string drinkOrdered) 
        {
            Node* newNode = new Node{customerName, drinkOrdered, nullptr};
    
            if (tailNode == nullptr) 
            { 
                headNode = newNode;
                tailNode = newNode;
            } 
            else 
            {
                tailNode->next = newNode;
                tailNode = newNode;
            }
    
            cout << customerName << " entered the line (ordered " << drinkOrdered << ")." << endl;
        }

        void deleteFromQueue() 
        {
            if (headNode == nullptr) 
            {
                cout << "No one to serve." << endl;
                return;
            }
    
            Node* temp = headNode;
            cout << headNode->customerName << " was served (" << headNode->drinkOrdered << ")." << endl;
            headNode = headNode->next;
    
            delete temp;

            if (!headNode)
            {
                tailNode = nullptr;
            }
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
    srand(time(0));

    CoffeeQueue queue;

    string customerNames[] = 
    {
        "Ava", "Liam", "Emma", "Noah", "Sophia",
        "Mason", "Isabella", "Lucas", "Mia", "James"
    };

    string drinksOrdered[] = 
    {
        "Latte", "Mocha", "Cold Brew", "Americano",
        "Matcha Latte", "Cappuccino", "Espresso Shot"
    };

    for (int i = 0; i < 3; i++) 
    {
        string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
        string drinkOrdered = drinksOrdered[rand() % MAX_DRINKS_ORDERED];

        queue.addToQueue(customerName, drinkOrdered);
    }

    queue.displayList();

    for (int round = 1; round <= 10; round++) 
    {
        cout << endl << "Round #" << round << ":" << endl;

        if (queue.isQueueEmpty()) 
        {
            cout << "Queue is empty this round." << endl;
        } 
        else
        {
            queue.deleteFromQueue();
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
            string drinkOrdered = drinksOrdered[rand() % MAX_DRINKS_ORDERED];
    
            queue.addToQueue(customerName, drinkOrdered);
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }

        queue.displayList();
    }

    return 0;
}

// Milestone 2