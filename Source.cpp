#include <iostream>
#include "Perceptron.h"

using std::cout;
using std::endl;

int main() {
	cout << "Hello, World" << endl;
	Perceptron perceptron;
	float inputs[] = { 100, 0.5 }; //Example input
	int output = perceptron.guesser(inputs);
	cout << output << endl;
}