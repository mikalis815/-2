#include <iostream>
#include <vector>

using namespace std;

// Класс для узла списка
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedListReversal {
public:
    // Функция для разворота списка
    static Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        
        while (current != nullptr) {
            Node* next = current->next; // сохраняем следующий узел
            current->next = prev;       // разворачиваем указатель
            prev = current;             // двигаем prev вперед
            current = next;             // двигаем current вперед
        }
        
        return prev; // новая голова списка
    }
    
    // Функция для печати списка
    static void printList(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " → ";
            }
            current = current->next;
        }
        cout << " → NULL" << endl;
    }
    
    // Создание списка из массива значений
    static Node* createList(const vector<int>& values) {
        if (values.empty()) return nullptr;
        
        Node* head = new Node(values[0]);
        Node* current = head;
        
        for (size_t i = 1; i < values.size(); i++) {
            current->next = new Node(values[i]);
            current = current->next;
        }
        
        return head;
    }
    
    // Функция для очистки памяти (важно в C++)
    static void deleteList(Node* head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    // Тест 1: обычный список
    cout << "Тест 1 - Обычный список:" << endl;
    vector<int> values1 = {1, 2, 3, 4, 5};
    Node* list1 = LinkedListReversal::createList(values1);
    
    cout << "Исходный: ";
    LinkedListReversal::printList(list1);
    
    Node* reversed1 = LinkedListReversal::reverse(list1);
    cout << "Развернутый: ";
    LinkedListReversal::printList(reversed1);
    
    // Тест 2: список из одного элемента
    cout << "\nТест 2 - Один элемент:" << endl;
    vector<int> values2 = {42};
    Node* list2 = LinkedListReversal::createList(values2);
    
    cout << "Исходный: ";
    LinkedListReversal::printList(list2);
    
    Node* reversed2 = LinkedListReversal::reverse(list2);
    cout << "Развернутый: ";
    LinkedListReversal::printList(reversed2);
    
    // Тест 3: пустой список
    cout << "\nТест 3 - Пустой список:" << endl;
    Node* list3 = nullptr;
    
    cout << "Исходный: ";
    LinkedListReversal::printList(list3);
    
    Node* reversed3 = LinkedListReversal::reverse(list3);
    cout << "Развернутый: ";
    LinkedListReversal::printList(reversed3);
    
    // Очистка памяти
    LinkedListReversal::deleteList(reversed1);
    LinkedListReversal::deleteList(reversed2);
    // list3 и reversed3 - nullptr, не требуют очистки
    
    return 0;
}