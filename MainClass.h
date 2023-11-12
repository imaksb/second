#pragma once
#include <iostream>

class MainClass {
private:
	int* numbers;
	int size;
public:
	MainClass();
	MainClass(int n);
	~MainClass();
	static int getNumber(const MainClass& number);
	MainClass& operator=(const MainClass& other);
	void input();

	// 2
	static void printNumber(const MainClass& number);
	friend bool isPrime(const MainClass& number);
	friend void PrimeFactors(MainClass& number);
	friend void findLCM(MainClass& first, MainClass& second);
	friend void ÑonvertToBase(MainClass& first, int base);

	//
	MainClass& operator++();
	MainClass& operator--();
	MainClass& operator!();
	MainClass& operator&(const MainClass& other); 
};