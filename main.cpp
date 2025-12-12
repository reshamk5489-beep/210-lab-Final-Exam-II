#include <string>
#include <iostream>
#include <deque>
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

    CoffeeQueue coffeeQueue;
    deque<string> muffinQueue;

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

        coffeeQueue.addToQueue(customerName, drinkOrdered);
    }

    for (int i = 0; i < 3; i++)
    {
        string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];

        muffinQueue.push_back(customerName + " (muffin)");
    }
                    
    coffeeQueue.displayList();

    for (int round = 1; round <= 10; round++) 
    {
        cout << endl << "Round #" << round << ":" << endl;

        if (coffeeQueue.isQueueEmpty()) 
        {
            cout << "Queue is empty this round." << endl;
        } 
        else
        {
            coffeeQueue.deleteFromQueue();
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
            string drinkOrdered = drinksOrdered[rand() % MAX_DRINKS_ORDERED];
    
            coffeeQueue.addToQueue(customerName, drinkOrdered);
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }

        coffeeQueue.displayList();

        if (!muffinQueue.empty()) 
        {
            cout << muffinQueue.front() << " was served (muffin)." << endl;
            muffinQueue.front();
        } 
        else 
        {
            cout << "No muffins to serve this round." << endl;
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
    
            muffinQueue.push_back(customerName + " (muffin)");
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }
    }

    return 0;
}