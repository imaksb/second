#include <iostream>

int main() {
    int number = 1234;
    int digitsCount = 0; // Переменная для подсчета количества цифр в числе
    int tempNumber = number;

    // Определяем количество цифр в числе
    while (tempNumber > 0) {
        tempNumber /= 10;
        digitsCount++;
    }

    int* digitsArray = new int[digitsCount]; // Выделяем память под массив цифр

    tempNumber = number;
    int index = digitsCount - 1; // Индекс для добавления цифр в массив

    // Разделяем число на цифры и добавляем их в массив
    while (tempNumber > 0) {
        digitsArray[index] = tempNumber % 10;
        tempNumber /= 10;
        index--;
    }

    // Выводим цифры из массива с использованием указателя
    std::cout << "Цифры в числе: ";
    for (int i = 0; i < digitsCount; i++) {
        std::cout << *(digitsArray + i) << " ";
    }

    delete[] digitsArray; // Освобождаем память, выделенную под массив

    return 0;
}
