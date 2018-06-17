#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifndef PERCEPTRON
#define PERCEPTRON

class Perceptron {

public:
	//Defualt Constructor
	Perceptron(){
		srand(time(0));
		cout << "Hello Perceptron | Default" << endl;
		weightSize = 0; 
		weightCapacity = defaultMaxWeightSize; //Default of 2
		weights = new float[weightCapacity];

		//Initialize Weights Randomly
		float randomValue;
		for (int i = 0; i < weightCapacity; i++) {
			// Generate psuedo-random value from -1 - 1
			randomValue = RandomFloat(weightLow, weightHigh);
			cout << randomValue << endl;
			weights[i] = randomValue;
			weightSize++;
		}
	}

	//Constructor
	Perceptron(const int maxWeightSize) {
		srand(time(0));
		cout << "Hello Perceptron" << endl;
		weightSize = 0; 
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

	void train(const float* inputs, int target) {
		int guess = guesser(inputs);
		int error = target - guess;
		
		//Tune all weights
		for (int i = 0; i < weightSize; i++) {
			weights[i] += error * inputs[i];
		}
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
		cout << number << endl;
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
