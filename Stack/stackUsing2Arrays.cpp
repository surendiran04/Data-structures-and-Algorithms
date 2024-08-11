#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1, q2; // Two queues to simulate stack

public:
    // Push an element onto the stack
    void push(int x) {
        // Push element to q2
        q2.push(x);

        // Push all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        std::swap(q1, q2);
    }

    // Remove the element on top of the stack
    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        q1.pop();
    }

    // Get the top element
    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1; // Return an invalid value for empty stack
        }
        return q1.front();
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Top element: " << stack.top() << std::endl; // 30
    
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // 20
    
    stack.pop();
    stack.pop();
    stack.pop(); // Stack is empty!

    std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
