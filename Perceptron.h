#include <iostream>
using namespace std;

#ifndef PERCEPTRON
#define PERCEPTRON

class Perceptron {
public:
	Perceptron(){
		cout << "Hello Perceptron | Default" << endl;
		weightSize = 0;
	}

	Perceptron(const int weightSize) {
		cout << "Hello Perceptron" << endl;
		this->weightSize = weightSize;
	}

private:
	static const int WEIGHT_MAX_SIZE = 2;
	float weight[WEIGHT_MAX_SIZE];
	int weightSize;

};

#endif // !PERCEPTRON
