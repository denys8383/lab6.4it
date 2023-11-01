#include <iostream>
#include <cstdlib>

// Функція для створення динамічного масиву подвійних чисел розміру 'n'.
void createArray(double*& arr, int n) {
    arr = new double[n]; // Виділяємо пам'ять для масиву.
}

// Функція для виведення вмісту масиву на екран.
void printArray(const double* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " "; // Виводимо елементи масиву на екран.
    }
    std::cout << std::endl;
}

// Функція для обчислення суми додатних елементів у масиві.
double Sum(const double* arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum += arr[i]; // Додаємо додатні елементи до суми.
        }
    }
    return sum;
}

// Функція для обчислення добутку елементів між максимальним і мінімальним елементами за модулем.
double DobytokMaxMin(const double* arr, int n) {
    int maxIdx = 0; // Індекс максимального за модулем елемента.
    int minIdx = 0; // Індекс мінімального за модулем елемента.

    for (int i = 1; i < n; i++) {
        if (std::abs(arr[i]) > std::abs(arr[maxIdx])) {
            maxIdx = i; // Знаходимо індекс максимального за модулем елемента.
        }
        if (std::abs(arr[i]) < std::abs(arr[minIdx])) {
            minIdx = i; // Знаходимо індекс мінімального за модулем елемента.
        }
    }

    int start = std::min(maxIdx, minIdx) + 1;
    int end = std::max(maxIdx, minIdx);

    double product = 1.0; // Початкове значення добутку.
    for (int i = start; i < end; i++) {
        product *= arr[i]; // Обчислюємо добуток елементів між максимальним і мінімальним.
    }

    return product;
}

// Функція для сортування непарних елементів за спаданням у масиві.
void Sort(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            for (int j = i; j < n; j++) {
                if (j % 2 != 0) {
                    if (arr[i] < arr[j]) {
                        std::swap(arr[i], arr[j]); // Порівнюємо і обмінюємо елементи для сортування.
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Rozmir masivy: ";
    std::cin >> n;

    double* arr = nullptr;
    createArray(arr, n); // Створюємо динамічний масив подвійних чисел.

    std::cout << "Vvedit " << n << " diysnih chisel: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i]; // Заповнюємо масив користувачем.
    }

    std::cout << "Masiv: ";
    printArray(arr, n); // Виводимо вміст масиву на екран.

    double sumPositives = Sum(arr, n);
    std::cout << "Suma dodatnih elementiv: " << sumPositives << std::endl;

    double product = DobytokMaxMin(arr, n);
    std::cout << "Dobutok elementiv mij maksimalnim i minimalnim za modulem: " << product << std::endl;

    Sort(arr, n); // Сортуємо непарні елементи за спаданням.

    std::cout << "Masiv pislya sortuvanya neparnih za spadannyam: ";
    printArray(arr, n); // Виводимо відсортований масив на екран.

    delete[] arr; // Звільнюємо виділену пам'ять для масиву.
    return 0;
}
