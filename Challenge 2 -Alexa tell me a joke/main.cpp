#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
    std::ifstream jokeFile("randomJokes.txt");

    if (!jokeFile) {
        std::cout << "Could not open randomJokes.txt.\n";
        return 1;
    }

    std::vector<std::string> jokes;
    std::string line;

    while (std::getline(jokeFile, line)) {
        if (line.find('?') != std::string::npos) {
            jokes.push_back(line);
        }
    }

    if (jokes.empty()) {
        std::cout << "There are no usable jokes in the file.\n";
        return 1;
    }

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<std::size_t> chooseJoke(
        0, jokes.size() - 1
    );

    std::string request;

    while (true) {
        std::cout << "Type Alexa, tell me a joke or type quit: ";

        if (!std::getline(std::cin, request) || request == "quit") {
            break;
        }

        if (request != "Alexa, tell me a joke") {
            std::cout << "Please type the phrase exactly as shown.\n";
            continue;
        }

        std::string joke = jokes[chooseJoke(generator)];
        auto questionMark = joke.find('?');

        std::cout << joke.substr(0, questionMark + 1) << '\n';
        std::cout << "Press Enter to see the punchline...";

        if (!std::getline(std::cin, request)) {
            break;
        }

        std::cout << joke.substr(questionMark + 1) << "\n\n";
    }

    return 0;
}