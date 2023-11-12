#include <iostream>
#include "MainClass.h"
#include <cmath>
MainClass::MainClass() {
    size = 1;
    numbers = new int[size];
    numbers[0] = 0;

}

MainClass::MainClass(int number) {
	size = 0;
	int tempNumber = number;

	while (tempNumber > 0) {
		tempNumber /= 10;
		size++;
	} 
	numbers = new int[size];
	int index = size - 1;

	while (number > 0) { 
		numbers[index--] = number % 10;
		number /= 10;
	}
}

int MainClass::getNumber(const MainClass& number) {
	int num = 0;
	for (int i = 0; i < number.size; i++) { 
		num = (num * 10) + number.numbers[i];
	}
	return num;
}


MainClass::~MainClass() {
	std::cout << "Delete";
	delete[] numbers;
}

MainClass& MainClass::operator=(const MainClass& secondObj) {
	delete[] numbers;

	size = secondObj.size;
	numbers = new int[size];
	for (int i = 0; i < size; i++) {
		numbers[i] = secondObj.numbers[i];
	}
	
	return *this;
}



void MainClass::printNumber(const MainClass& number) {
	for (int i = 0; i < number.size; i++) {
		std::cout << number.numbers[i];
	} 
	std::cout << std::endl;
}

void MainClass::input() {
	int number;
	std::cout << "Enter number: ";
	std::cin >> number;

	size = 0;
	int tempNumber = number;

	while (tempNumber > 0) {
		tempNumber /= 10;
		size++;
	}
	numbers = new int[size];
	int index = size - 1;

	while (number > 0) {
		numbers[size - index - 1] = number % 10;
		number /= 10;
		index--;
	}
}

bool isPrime(const MainClass& number) {
	int intNumber = MainClass::getNumber(number);
	if (intNumber <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(intNumber); ++i) {
		if (intNumber % i == 0) {
			return false;
		}
	}
	return true;
}

void PrimeFactors(MainClass& number) {
	int intNumber = MainClass::getNumber(number);

	while (intNumber % 2 == 0) {
		std::cout << 2 << " ";
		intNumber = intNumber / 2;
	}

	for (int i = 3; i <= sqrt(intNumber); i = i + 2) {
		while (intNumber % i == 0) {
			std::cout << i << " ";
			intNumber = intNumber / i;
		}
	}

	if (intNumber > 2)
		std::cout << intNumber << " ";
}

void findLCM(MainClass& first, MainClass& second) {
	int firstNumber = MainClass::getNumber(first);
	int secondNumber = MainClass::getNumber(second);

	int a = firstNumber;
	int b = secondNumber;
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	std::cout << (firstNumber * secondNumber) / a;
}

void ÑonvertToBase(MainClass& object, int base) {
	int intNumber = MainClass::getNumber(object);
	int i;
	switch (base) {
	case 2:
		int binaryNum[32];

		i = 0;
		while (intNumber > 0) {
			binaryNum[i] = intNumber % 2;
			intNumber = intNumber / 2;
			i++;
		}

		for (int j = i - 1; j >= 0; j--)
			std::cout << binaryNum[j];
		break;
	case 8:
		int octalNum[100];

		i = 0;
		while (intNumber != 0) {
			octalNum[i] = intNumber % 8;
			intNumber = intNumber / 8;
			i++;
		}
		
		for (int j = i - 1; j >= 0; j--)
			std::cout << octalNum[j];
		break;
	case 16:
		char hexaDeciNum[100];

		i = 0;
		while (intNumber != 0) {
			int temp = 0;

			temp = intNumber % 16;

			if (temp < 10) {
				hexaDeciNum[i] = temp + 48;
				i++;
			}
			else {
				hexaDeciNum[i] = temp + 55;
				i++;
			}

			intNumber = intNumber / 16;
		}
		for (int j = i - 1; j >= 0; j--)
			std::cout << hexaDeciNum[j];
	}

}

MainClass& MainClass::operator++() {
	int sum = 0;
	for (int i = 0; i < this->size; i++) {
		sum += *(this->numbers + i);
	}

	size = 0;
	int tempNumber = sum;
	while (tempNumber > 0) {
		tempNumber /= 10;
		size++;
	}
	numbers = new int[size];
	int index = size - 1;

	while (sum > 0) {
		numbers[size - index - 1] = sum % 10;
		sum /= 10;
		index--;
	}

	return *this;
}
MainClass& MainClass::operator--() { 
	 
	for (int i = size - 1; i >= 0; i--) { 
		if (numbers[i] == 0) { 
			size--;
		}
		else {
			break;
		}
	}

	return *this;
}

MainClass& MainClass::operator!() {
	--*(this);
	for (int i = 0; i < size / 2; ++i) {
		int temp = numbers[i];
		numbers[i] = numbers[size - 1 - i];
		numbers[size - 1 - i] = temp;
	}
	return *this;
}

MainClass& MainClass::operator&(const MainClass& other) {
	int first = MainClass::getNumber(*this);
	int second = MainClass::getNumber(other);

	std::cout << first / second;
}