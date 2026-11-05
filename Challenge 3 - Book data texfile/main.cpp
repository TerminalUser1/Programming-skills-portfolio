#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Book {
public:
    std::string title, author, id;
    int pages;
    bool borrowed;

    void display() const {
        std::cout << "\nTitle: " << title
                  << "\nAuthor: " << author
                  << "\nPages: " << pages
                  << "\nID: " << id
                  << "\nStatus: "
                  << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

int main() {
    std::ifstream file("bookData.txt");
    if (!file) {
        std::cout << "Could not open bookData.txt.\n";
        return 1;
    }

    std::vector<Book> books;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream row(line);
        Book book;
        std::string pagesText, status;

        std::getline(row, book.title, ',');
        std::getline(row, book.author, ',');
        std::getline(row, pagesText, ',');
        std::getline(row, book.id, ',');
        std::getline(row, status);

        if (!status.empty() && status.back() == '\r') {
            status.pop_back();
        }

        try {
            std::size_t used;
            book.pages = std::stoi(pagesText, &used);
            if (used != pagesText.size() || book.pages <= 0 ||
                book.id.empty() || (status != "true" && status != "false")) {
                throw std::invalid_argument("Invalid data");
            }
        } catch (const std::exception&) {
            std::cout << "Invalid book data: " << line << '\n';
            return 1;
        }

        book.borrowed = (status == "true");
        books.push_back(book);
    }
    file.close();

    std::string choice;
    while (true) {
        std::cout << "\n1. View all books\n2. View one book\n"
                  << "3. Borrow a book\n4. Return a book\n5. Quit\n"
                  << "Choose an option: ";
        if (!std::getline(std::cin, choice) || choice == "5") break;

        if (choice == "1") {
            for (const Book& book : books) book.display();
            continue;
        }
        if (choice != "2" && choice != "3" && choice != "4") {
            std::cout << "Please choose an option from 1 to 5.\n";
            continue;
        }

        std::string id;
        std::cout << "Enter book ID, for example 001: ";
        if (!std::getline(std::cin, id)) break;

        Book* selected = nullptr;
        for (Book& book : books) {
            if (book.id == id) selected = &book;
        }

        if (selected == nullptr) {
            std::cout << "Book not found.\n";
        } else if (choice == "2") {
            selected->display();
        } else if ((choice == "3") == selected->borrowed) {
            std::cout << "The book already has that status.\n";
        } else {
            selected->borrowed = (choice == "3");
            std::ofstream output("bookData.txt");
            for (const Book& book : books) {
                output << book.title << ',' << book.author << ','
                       << book.pages << ',' << book.id << ','
                       << (book.borrowed ? "true" : "false") << '\n';
            }
            output.close();
            if (!output) {
                std::cout << "Could not save the book data.\n";
                return 1;
            }
            std::cout << "Book status updated.\n";
        }
    }

    return 0;
}
