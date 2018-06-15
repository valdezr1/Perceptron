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
		weightCapacity = defaultMaxWeightSize; //Default of 2
		weights = new float[weightCapacity];

		//Initialize Weights Randomly
		float randomValue;
		for (int i = 0; i < weightCapacity; i++) {
			// Generate psuedo-random value from -1 - 1
			randomValue = RandomFloat(weightLow, weightHigh);
			weights[i] = randomValue;
			weightSize++;
		}
	}

	//Constructor
	Perceptron(const int maxWeightSize) {
		cout << "Hello Perceptron" << endl;
		weightCapacity = maxWeightSize;
		weights = new float[weightCapacity];

		//Initialize Weights Randomly
		float randomValue;
		for (int i = 0; i < weightCapacity; i++) {
			// Generate psuedo-random value from -1 - 1
			randomValue = RandomFloat(weightLow, weightHigh);
			weights[i] = randomValue;
			weightSize++;
		}
	}

	int guesser(const float* inputs) {
		float sum = 0;
		for (int i = 0; i < weightSize; i++) {
			sum += inputs[i] * weights[i];
		}
		return sign(sum);
	}

	//Destructor 
	~Perceptron() {
		delete[] weights;
	}

private:
	float RandomFloat(float a, float b) {
		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = b - a;
		float r = random * diff;
		return a + r;
	}

	// Activation Function
	int sign(float number) {
		if (number < 0)
			return -1;
		else
			return 1;
	}

	const int defaultMaxWeightSize = 2;
	const float weightLow = -1.0;
	const float weightHigh = 1.0;

	float* weights;
	int weightCapacity;
	int weightSize;

};

#endif // !PERCEPTRON
