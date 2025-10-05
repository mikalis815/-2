// Простое решение в одном классе
public class LinkedListReversal {
    
    // Внутренний класс для узла списка
    static class Node {
        int data;
        Node next;
        
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    
    // Функция для разворота списка
    public static Node reverse(Node head) {
        Node prev = null;
        Node current = head;
        
        while (current != null) {
            Node next = current.next; // сохраняем следующий узел
            current.next = prev;      // разворачиваем указатель
            prev = current;           // двигаем prev вперед
            current = next;           // двигаем current вперед
        }
        
        return prev; // новая голова списка
    }
    
    // Функция для печати списка
    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data);
            if (current.next != null) {
                System.out.print(" → ");
            }
            current = current.next;
        }
        System.out.println(" → NULL");
    }
    
    // Создание списка из массива значений
    public static Node createList(int[] values) {
        if (values.length == 0) return null;
        
        Node head = new Node(values[0]);
        Node current = head;
        
        for (int i = 1; i < values.length; i++) {
            current.next = new Node(values[i]);
            current = current.next;
        }
        
        return head;
    }
    
    public static void main(String[] args) {
        // Тест 1: обычный список
        System.out.println("Тест 1 - Обычный список:");
        int[] values1 = {1, 2, 3, 4, 5};
        Node list1 = createList(values1);
        
        System.out.print("Исходный: ");
        printList(list1);
        
        Node reversed1 = reverse(list1);
        System.out.print("Развернутый: ");
        printList(reversed1);
        
        // Тест 2: список из одного элемента
        System.out.println("\nТест 2 - Один элемент:");
        int[] values2 = {42};
        Node list2 = createList(values2);
        
        System.out.print("Исходный: ");
        printList(list2);
        
        Node reversed2 = reverse(list2);
        System.out.print("Развернутый: ");
        printList(reversed2);
        
        // Тест 3: пустой список
        System.out.println("\nТест 3 - Пустой список:");
        Node list3 = null;
        
        System.out.print("Исходный: ");
        printList(list3);
        
        Node reversed3 = reverse(list3);
        System.out.print("Развернутый: ");
        printList(reversed3);
    }
}