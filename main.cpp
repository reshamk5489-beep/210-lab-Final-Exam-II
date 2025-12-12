#include <string>
using namespace std;

struct Node 
{
    string customerName;
    string drinkOrdered;
    Node* next;
};

class CoffeeQueue {
    private:
        Node* headNode;
        Node* tailNode;
    
    public:
        CoffeeQueue() 
        {
            headNode = tailNode = nullptr;
        }
    };
    

int main()
{



    
    return 0;
}