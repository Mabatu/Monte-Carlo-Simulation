#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


#define NUMBERS 100000

int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}
int main() {
    int coprimes = 0;
    srand(time(0));
    for (int i = 0; i < NUMBERS; i++) {
        int a = rand() % 100 + 1;
        int b = rand() % 100 + 1;
        int value = gcd(a, b);
        if (value == 1) {
            coprimes++;
        }    
   }
    //std::cout << coprimes;
    double my_pi = sqrt(6.0 / (coprimes / NUMBERS));
    std::cout << std::endl << "here" << my_pi << std::endl;
} 
