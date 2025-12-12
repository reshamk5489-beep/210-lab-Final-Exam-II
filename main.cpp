#include <string>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX_CUSTOMER_NAMES = 10;
const int MAX_DRINKS_ORDERED = 7;
const int MAX_MUFFINS = 5;
const int MAX_BRACELETS = 5;
const int MAX_SMOOTHIES = 5;

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
            cout << endl << "Coffee queue:" << endl;
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
    vector<string> braceletQueue;
    queue<string> smoothieQueue;

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

    string muffins[] = 
    {
        "Blueberry","Chocolate Chip","Banana","Bran","Cranberry"
    };

    string bracelets[] = 
    {
        "Red","Blue","Green","Yellow","Purple"
    };

    string smoothies[] = 
    {
        "Strawberry","Mango","Banana","Blueberry","Spinach"
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
        string muffinName = muffins[rand() % MAX_MUFFINS];

        muffinQueue.push_back(customerName + " - " + muffinName);
    }

    for (int i = 0; i < 3; i++)
    {
        string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
        string braceletName = bracelets[rand() % MAX_BRACELETS];

        braceletQueue.push_back(customerName + " - " + braceletName);
    }

    for (int i = 0; i < 3; i++)
    {
        string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
        string smoothieName = smoothies[rand() % MAX_SMOOTHIES];

        smoothieQueue.push(customerName + " - " + smoothieName);
    }
                    
    coffeeQueue.displayList();

    cout << endl << "Muffin Queue: " << endl;
    for (auto& c : muffinQueue) 
    {
        cout << "\t" << c << endl;
    }

    cout << endl << "Bracelet Queue: " << endl;
    for (auto& c : braceletQueue) 
    {
        cout << "\t" << c << endl;
    }

    cout << endl << "Smoothie Queue: " << endl;
    queue<string> tempQueue = smoothieQueue;
    while (!tempQueue.empty()) 
    { 
        cout << "\t" << tempQueue.front() << endl;
        tempQueue.pop();
    }

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
            cout << muffinQueue.front() << " was served." << endl;
            muffinQueue.pop_front();
        } 
        else 
        {
            cout << "No muffins to serve this round." << endl;
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
            string muffinName = muffins[rand() % MAX_MUFFINS];

            muffinQueue.push_back(customerName + " - " + muffinName);
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }

        cout << endl << "Muffin Queue: " << endl;
        for (auto& c : muffinQueue) 
        {
            cout << "\t" << c << endl;
        }

        if (!braceletQueue.empty()) 
        {
            cout << braceletQueue.front() << " was served." << endl;
            braceletQueue.erase(braceletQueue.begin());
        } 
        else 
        {
            cout << "No bracelets to serve this round." << endl;
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
            string braceletName = bracelets[rand() % MAX_BRACELETS];
    
            braceletQueue.push_back(customerName + " - " + braceletName);
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }

        cout << endl << "Bracelet Queue: " << endl;
        for (auto& c : braceletQueue) 
        {
            cout << "\t" << c << endl;
        }

        if (!smoothieQueue.empty()) 
        {
            cout << smoothieQueue.front() << " was served." << endl;
            smoothieQueue.pop();
        } 
        else 
        {
            cout << "No smoothies to serve this round." << endl;
        }

        if (rand() % 2 == 0) 
        {
            string customerName = customerNames[rand() % MAX_CUSTOMER_NAMES];
            string smoothieName = smoothies[rand() % MAX_SMOOTHIES];

            smoothieQueue.push(customerName + " - " + smoothieName);
        } 
        else 
        {
            cout << "No new customer this round." << endl;
        }

        cout << endl << "Smoothie Queue: " << endl;
        queue<string> tempQueue = smoothieQueue;
        while (!tempQueue.empty()) 
        { 
            cout << "\t" << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }

    return 0;
}