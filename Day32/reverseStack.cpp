#include <iostream>
#include <stack>

void bottominsert(int x, std::stack<int>& stack)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    int y = stack.top();
    stack.pop();
    bottominsert(x, stack);
    stack.push(y);
}

void reverseStack(std::stack<int>& stack)
{
    if (stack.empty() || stack.size() == 1)
        return;
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    bottominsert(temp, stack);
}

int main()
{
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    std::cout << "Original Stack: ";
    while (!myStack.empty())
    {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Push elements back onto the stack in reverse order
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    reverseStack(myStack);

    std::cout << "Reversed Stack: ";
    while (!myStack.empty())
    {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
