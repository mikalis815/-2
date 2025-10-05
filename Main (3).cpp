#include <iostream>
#include <climits> // для INT_MIN

using namespace std;

int main() {
    // Используем заранее заданные числа вместо ввода пользователя
    int numbers[] = {10, 25, 8, 42, 15};
    int sum = 0;
    int max = INT_MIN; // минимальное значение int
    
    cout << "Используемые числа: 10, 25, 8, 42, 15" << endl;
    
    // 1. Выводим все числа
    cout << "Числа: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // 2. Находим сумму и максимальное число
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
        
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    
    // Выводим результаты
    cout << "Сумма всех чисел: " << sum << endl;
    cout << "Наибольшее число: " << max << endl;
    
    return 0;
}