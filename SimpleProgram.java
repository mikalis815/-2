public class SimpleProgram {
    public static void main(String[] args) {
        // Используем заранее заданные числа вместо ввода пользователя
        int[] numbers = {10, 25, 8, 42, 15};
        int sum = 0;
        int max = Integer.MIN_VALUE;
        
        System.out.println("Используемые числа: 10, 25, 8, 42, 15");
        
        // 1. Выводим все числа
        System.out.print("Числа: ");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println();
        
        // 2. Находим сумму и максимальное число
        for (int i = 0; i < numbers.length; i++) {
            sum += numbers[i];
            
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        
        // Выводим результаты
        System.out.println("Сумма всех чисел: " + sum);
        System.out.println("Наибольшее число: " + max);
    }
}