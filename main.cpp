#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdint>

//Define circle parameters.
#define CIRCLE_RADIUS 1.0
#define X_CENTER 2.0 
#define Y_CENTER 2.0

// Width of the square region where random points are selected from.
#define REGION_WIDTH 6.0

//Define square parameters.
#define MAX_X 5.0
#define MAX_Y 5.0

#define MIN_X 4.0
#define MIN_Y 4.0

//Maximum number of iteration = 4,294,967,295
#define ITERATIONS 100000000

//Function to check whether a randomly picked point is inside the circle.
bool insideCircle(double x, double y) {
	// Returns true if the point (x, y) is inside the circle.
	if (pow((x - X_CENTER), 2) + pow((y - Y_CENTER), 2) <= pow(CIRCLE_RADIUS, 2)) {
		return true;
	}
	else {
		return false;
	}
}

//Function to check whether a randomly picked point is inside the square.
bool insideSquare(double x, double y) {
	// Returns true if the point (x, y) is inside the square.
	if (x >= MIN_X && x <= MAX_X) {
		if (y >= MIN_X && y <= MAX_Y) {
			return true;
		}			
	}
	return false;
}

int main() {
	// Counters for points that fall inside the circle and square.
	int circle = 0;
	int square = 0;
        //Open a file to log the number of points within the circle and square. 
	std::ofstream outputFile("data.csv");
	outputFile << "ITERATION,Estimate Pi" << std::endl;

	// Seed the random number generator with the current time for better randomness.
	srand(time(0));
	for (uint32_t i = 0; i < ITERATIONS; i++) {
		//Generate random numbers within the region.
		double x = static_cast<double>(rand()) / RAND_MAX * REGION_WIDTH;
		double y = static_cast<double>(rand()) / RAND_MAX * REGION_WIDTH;
		
		//Check whether the point is within the circle or square.
		if (insideCircle(x, y)) {
			circle += 1;
		}
		if (insideSquare(x, y)) {
			square += 1;
		}
		outputFile << i + 1 << ',' static_cast<double>(circle) / static_cast<double>(square) << std::endl;
	}
	std::cout << std::endl << "Monte Carlo simulation complete!" << std::endl;
	
	//Estimate the value of Pi and print it out to the terminal.
	double MY_PI = static_cast<double>(circle) / static_cast<double>(square);
	std::cout << MY_PI;
	outputFile.close();
	return 0;
}
