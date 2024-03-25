#include <iostream>
#include <stdexcept>
using namespace std;
template <class type>
class Stack {
private:
    type* arr;
    int size;
    int top;

public:
    Stack(int size) : top(-1), size(size) {
     arr = new type[size];
     if (!arr) {
    throw runtime_error("Memory allocation failed for stack");
    }
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty()// O(1)
    {
        return top == -1;

    }

    bool isFull()// O(1)
     {
        return top == size - 1;
    }
    void push( type val)// O(1)
    {
        if (isFull()) {
            throw runtime_error("Stack overflow");
        }
        arr[++top] = val;
    }

    void pop() // O(1)
    {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        top--;
    }

    type getTop()  // O(1)
    {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return arr[top];
    }

    void clearStack() // O(1)
    {
        top = -1;
    }

    void display()  // o(N)
     {
        if (isEmpty()) {
            cout << "***** There is no element *****\n\n";
            return;
        }
        cout << "***** All elements *****\n\n";
        int number=1;
        for (int i = top; i >= 0; i--)
            {
            cout << "Item " << number << " :" << arr[i] << endl;
        number++;
        }
    }
        void reverse()  // O(N/2)
        {
        if (isEmpty()) {
            return;
                    }
        for (int i = 0; i <= top / 2; i++) {
            swap(arr[i], arr[top - i]);
        }
    }
};
int main() {
   Stack<int>number(3);
    for(int i=0;i<3;i++){
   int num;
     cout<<"num "<<i+1<<" :";
           cin>>num;
    number.push(num);
}
    system("cls");

       number.display();
          number.reverse();
        number.display();
         number.clearStack();
          number.display();
  return 0;

}
