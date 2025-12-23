#include <iostream>
#include <fstream>
#include <string>
#include <set>

struct Author {
    std::string surname;
    std::string name;
    std::string patronymic;

    bool operator<(const Author& other) const {
        if (surname != other.surname) return surname < other.surname;
        if (name != other.name) return name < other.name;
        return patronymic < other.patronymic;
    }

    bool operator!=(const Author& other) const {
        return surname != other.surname || name != other.name || patronymic != other.patronymic;
    }

    bool operator==(const Author& other) const {
        return surname == other.surname && name == other.name && patronymic == other.patronymic;
    }

    std::string toString() const {
        return surname + " " + name + " " + patronymic;
    }
};

struct Book {
    int udcNumber;
    std::set<Author> authors;
    std::string title;
    int year;

    bool operator<(const Book& other) const {
        return title < other.title;
    }

    void print() const {
        std::cout << "UDC: " << udcNumber << "\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Authors: ";

        auto it = authors.begin();
        if (it != authors.end()) {
            std::cout << it->toString();
            ++it;
            for (; it != authors.end(); ++it) {
                std::cout << ", " << it->toString();
            }
        }
        std::cout << "\n------------------------\n";
    }
};

class Library {
private:
    std::set<Book> books;

public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "Error opening file!\n";
            return;
        }

        Book book;
        int authorCount;

        while (file >> book.udcNumber) {
            file >> authorCount;
            file.ignore();
            book.authors.clear();

            for (int i = 0; i < authorCount; ++i) {
                Author author;
                std::getline(file, author.surname);
                std::getline(file, author.name);
                std::getline(file, author.patronymic);
                book.authors.insert(author);
            }

            std::getline(file, book.title);
            file >> book.year;
            file.ignore();

            books.insert(book);
        }

        std::cout << "Loaded " << books.size() << " books.\n";
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Error saving file!\n";
            return;
        }

        for (const auto& book : books) {
            file << book.udcNumber << "\n";
            file << book.authors.size() << "\n";
            for (const auto& author : book.authors) {
                file << author.surname << "\n";
                file << author.name << "\n";
                file << author.patronymic << "\n";
            }
            file << book.title << "\n";
            file << book.year << "\n";
        }
    }

    void addBook() {
        Book book;
        std::cout << "Enter UDC number: ";
        std::cin >> book.udcNumber;
        std::cin.ignore();

        std::cout << "Enter book title: ";
        std::getline(std::cin, book.title);

        std::cout << "Enter publication year: ";
        std::cin >> book.year;
        std::cin.ignore();

        int authorCount;
        std::cout << "Enter number of authors: ";
        std::cin >> authorCount;
        std::cin.ignore();

        for (int i = 0; i < authorCount; ++i) {
            Author author;
            std::cout << "Author " << i + 1 << ":\n";
            std::cout << "Surname: ";
            std::getline(std::cin, author.surname);
            std::cout << "Name: ";
            std::getline(std::cin, author.name);
            std::cout << "Patronymic: ";
            std::getline(std::cin, author.patronymic);
            book.authors.insert(author);
        }

        books.insert(book);
        std::cout << "Book added.\n";
    }

    void removeBook() {
        std::string title;
        std::cout << "Enter book title to remove: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it != books.end()) {
            books.erase(it);
            std::cout << "Book removed.\n";
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void searchByTitle() {
        std::string title;
        std::cout << "Enter title to search: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it != books.end()) {
            it->print();
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void searchByAuthor() {
        Author author;
        std::cout << "Enter author surname: ";
        std::getline(std::cin, author.surname);
        std::cout << "Enter author name: ";
        std::getline(std::cin, author.name);
        std::cout << "Enter author patronymic: ";
        std::getline(std::cin, author.patronymic);

        std::cout << "Books by " << author.toString() << ":\n";
        bool found = false;

        for (const auto& book : books) {
            if (book.authors.find(author) != book.authors.end()) {
                book.print();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No books by this author found.\n";
        }
    }

    void addAuthorToBook() {
        std::string title;
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it == books.end()) {
            std::cout << "Book not found.\n";
            return;
        }

        Book modifiedBook = *it;
        books.erase(it);

        Author author;
        std::cout << "Enter new author surname: ";
        std::getline(std::cin, author.surname);
        std::cout << "Enter new author name: ";
        std::getline(std::cin, author.name);
        std::cout << "Enter new author patronymic: ";
        std::getline(std::cin, author.patronymic);

        if (modifiedBook.authors.find(author) != modifiedBook.authors.end()) {
            std::cout << "This author already exists.\n";
            books.insert(modifiedBook);
            return;
        }

        modifiedBook.authors.insert(author);
        books.insert(modifiedBook);
        std::cout << "Author added.\n";
    }

    void removeAuthorFromBook() {
        std::string title;
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it == books.end()) {
            std::cout << "Book not found.\n";
            return;
        }

        Book modifiedBook = *it;
        books.erase(it);

        Author author;
        std::cout << "Enter author surname to remove: ";
        std::getline(std::cin, author.surname);
        std::cout << "Enter author name: ";
        std::getline(std::cin, author.name);
        std::cout << "Enter author patronymic: ";
        std::getline(std::cin, author.patronymic);

        auto authorIt = modifiedBook.authors.find(author);
        if (authorIt == modifiedBook.authors.end()) {
            std::cout << "Author not found.\n";
            books.insert(modifiedBook);
            return;
        }

        modifiedBook.authors.erase(authorIt);

        if (modifiedBook.authors.empty()) {
            std::cout << "Last author removed. Book will be deleted.\n";
        } else {
            books.insert(modifiedBook);
            std::cout << "Author removed.\n";
        }
    }

    void displayAll() {
        std::cout << "\nTotal books in library: " << books.size() << "\n";
        for (const auto& book : books) {
            book.print();
        }
    }

private:
    std::set<Book>::iterator findBookByTitle(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                return it;
            }
        }
        return books.end();
    }
};

void displayMenu() {
    std::cout << "\n=== Library Menu ===\n";
    std::cout << "1. Load data from file\n";
    std::cout << "2. Save data to file\n";
    std::cout << "3. Add book\n";
    std::cout << "4. Remove book\n";
    std::cout << "5. Search book by title\n";
    std::cout << "6. Search books by author\n";
    std::cout << "7. Add author to book\n";
    std::cout << "8. Remove author from book\n";
    std::cout << "9. Show all books\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose action: ";
}

int main() {
    Library library;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
            case 1: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::getline(std::cin, filename);
                library.loadFromFile(filename);
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Enter filename for saving: ";
                std::getline(std::cin, filename);
                library.saveToFile(filename);
                break;
            }
            case 3:
                library.addBook();
                break;
            case 4:
                library.removeBook();
                break;
            case 5:
                library.searchByTitle();
                break;
            case 6:
                library.searchByAuthor();
                break;
            case 7:
                library.addAuthorToBook();
                break;
            case 8:
                library.removeAuthorFromBook();
                break;
            case 9:
                library.displayAll();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
