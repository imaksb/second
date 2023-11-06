#include <iostream>
#include "MainClass.h"

MainClass::MainClass() {
	setOfNumbers = new int[size];
	setOfNumbers[0] = 0;
}

MainClass::MainClass(int number) {
	size = 0;
	int tempNumber;

	while (tempNumber > 0) {
		tempNumber /= 10;
		size++;
	}

	setOfNumbers = new int[size];
	int index = size - 1; 

	while (tempNumber > 0) {
		setOfNumbers[index] = tempNumber % 10;
		tempNumber /= 10;
		index--;
	}

}