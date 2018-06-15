#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef PERCEPTRON
#define PERCEPTRON

class Perceptron {

public:
	//Defualt Constructor
	Perceptron(){
		cout << "Hello Perceptron | Default" << endl;
		weightSize = 0;
	}

	//Constructor
	Perceptron(const int weightSize) {
		cout << "Hello Perceptron" << endl;
		this->weightSize = weightSize;

		//Initialize Weights Randomly
		float Low = -1.0, High = 1.0, randomValue;
		for (int i = 0; i < weightSize; i++) {
			// Generate psuedo-random value from -1 - 1
			randomValue = Low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (High - Low)));
			weights[i] = randomValue;
		}
	}

private:
	static const int WEIGHT_MAX_SIZE = 2;
	float weights[WEIGHT_MAX_SIZE];
	int weightSize;

};

#endif // !PERCEPTRON
