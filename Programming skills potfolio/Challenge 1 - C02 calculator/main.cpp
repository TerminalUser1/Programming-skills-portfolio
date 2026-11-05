#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

bool getDistance(double& distance) {
    std::string input;

    while (true) {
        std::cout << "Enter the distance travelled in miles: ";
        if (!std::getline(std::cin, input)) {
            return false;
        }

        std::istringstream entry(input);
        char extra;
        if (entry >> distance && std::isfinite(distance) &&
            distance >= 0 && !(entry >> extra)) {
            return true;
        }

        std::cout << "Please enter a valid distance of zero or more.\n";
    }
}

bool getFuelType(int& fuelType) {
    std::string input;

    while (true) {
        std::cout << "Choose a fuel (1 for diesel, 2 for petrol): ";
        if (!std::getline(std::cin, input)) {
            return false;
        }

        if (input == "1" || input == "2") {
            fuelType = (input == "1") ? 1 : 2;
            return true;
        }

        std::cout << "Please enter 1 or 2.\n";
    }
}

double calculateEmissions(double distance, int fuelType) {
    const double litresUsed = distance / 100.0 * 9.66;
    const double emissionsPerLitre = (fuelType == 1) ? 2.68 : 2.31;

    return litresUsed * emissionsPerLitre;
}

int main() {
    double distance = 0.0;
    int fuelType = 0;

    if (!getDistance(distance) || !getFuelType(fuelType)) {
        return 0;
    }

    const double emissions = calculateEmissions(distance, fuelType);

    std::cout << std::fixed << std::setprecision(2)
              << "Estimated CO2 emissions: " << emissions << " kg\n";
    return 0;
}