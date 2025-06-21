#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdint>

//Define circle parameters
#define CIRCLE_RADIUS 1.0
#define X_CENTER 2.0 
#define Y_CENTER 2.0

//Define square paramaters
#define MAX_X 5.0
#define MAX_Y 5.0

#define MIN_X 4.0
#define MIN_Y 4.0

//Maximum number of iteration = 4,294,967,295
#define ITERATIONS 100000000

//Function to check whether randomly picked co-ordinate is inside the circle.
bool insideCircle(double x, double y) {
	if (pow((x - X_CENTER), 2) + pow((y - Y_CENTER), 2) <= pow(CIRCLE_RADIUS, 2)) {
		return true;
	}
	else {
		return false;
	}
}

//Function to check whether randomly picked co-ordinate is inside the square.
bool insideSquare(double x, double y) {
	if (x >= MIN_X && x <= MAX_X) {
		if (y >= MIN_X && y <= MAX_Y) {
			return true;
		}			
	}
	return false;
}

int main() {
	int circle = 0;
	int square = 0;

	std::ofstream outputFile("data.csv");
	outputFile << "Circle,square," << std::endl;

	srand(time(0));
	for (uint32_t i = 0; i < ITERATIONS; i++) {
		double x = static_cast<double>(rand()) / RAND_MAX * 6.0;
		double y = static_cast<double>(rand()) / RAND_MAX * 6.0;
		//std::cout << i + 1 << " " << x << ',' << y << std::endl;
		if (insideCircle(x, y)) {
			circle += 1;
		}
		if (insideSquare(x, y)) {
			square += 1;
		}
		outputFile << i << ',' << circle << ',' << square << ',' << std::endl;
	}
	std::cout << std::endl << "Monte Carlo simulation complete!" << std::endl;
	double MY_PI = static_cast<double>(circle) / static_cast<double>(square);
	std::cout << MY_PI;
	outputFile.close();
	return 0;
}
