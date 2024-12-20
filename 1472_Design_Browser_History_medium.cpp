class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string url = "", Node* prev = nullptr, Node* next = nullptr) {
        this->url = url;
        this->prev = prev;
        this->next = next;
    }
};

class BrowserHistory {
private:
    Node* currentNode;
public:
    BrowserHistory(string homepage) {
        currentNode = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        currentNode->next = newNode;
        newNode->prev = currentNode;
        currentNode = newNode;
    }
    
    string back(int steps) {
        int currentSteps = 0;
        while (currentNode->prev != nullptr && currentSteps < steps) {
            currentNode = currentNode->prev;
            currentSteps++;
        }
        return currentNode->url;
    }
    
    string forward(int steps) {
        int currentSteps = 0;
        while (currentNode->next != nullptr && currentSteps < steps) {
            currentNode = currentNode->next;
            currentSteps++;
        }
        return currentNode->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

