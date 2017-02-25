#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *nextNode = nullptr;
    Node(int _value){
        value = _value;
    }
};

struct List{
    unsigned int size; // size
    Node * firstNode; // pointer to first element

    void listInit(){
        size = 0;
        firstNode = nullptr;
    }

    void push_back(int value){
        Node *node = new Node(value);
        if(firstNode == nullptr){
            firstNode = node;
            size += 1;
        }else{
            Node *tmp = firstNode;
            while(tmp->nextNode != nullptr){
                tmp = tmp->nextNode;
            }
            tmp->nextNode = node;
            size += 1;
        }

    }

    void push_front(int value){
        Node *node = new Node(value);
        if (firstNode == nullptr){
            firstNode = node;
            size += 1;
        } else {
            Node *tmp = firstNode;
            firstNode = node;
            firstNode->nextNode = tmp;
            size += 1;
        }
    }


    void pop_back(){
        if(firstNode == nullptr){
            cout << "Operation not allowed";
        } else {
            Node *tmp = firstNode;
            for (int i = 0; i < size - 1; ++i) {

                tmp = tmp->nextNode;
            }
            tmp->nextNode = nullptr;
            size -= 1;
        }
    }

    void pop_front(){
        if (firstNode == nullptr){
            cout << "Operation not allowed";
        } else {
            Node * tmp = firstNode;
            if (tmp->nextNode != nullptr){
                tmp = tmp->nextNode;
                firstNode = tmp;
            } else {
                cout << "Operation not allowed";
            }
            delete tmp;
        }

    }

    void removeAtIndex(int index){
        if(firstNode == nullptr || size < index){
            cout << "operation not allowed";
        }else{
            Node *tmp = firstNode;
            Node *switchNode = firstNode;
            for (int i = 0; i < index ; ++i) {
                tmp = tmp->nextNode;
                switchNode = switchNode->nextNode;
            }
            tmp->nextNode = switchNode->nextNode;
        }
    }

};

int main() {

    List lista;
    lista.listInit();
    lista.push_back(2);
    lista.push_back(4);
    lista.push_back(6);
    lista.push_front(1);
    cout << lista.size << endl;
    cout << lista.size << endl;
    cout << lista.firstNode->nextNode->nextNode->nextNode->value << endl;
    lista.removeAtIndex(2);
    cout << lista.firstNode->nextNode->nextNode->value;

}