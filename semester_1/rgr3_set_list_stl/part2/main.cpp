#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

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
        std::cout << "УДК: " << udcNumber << "\n";
        std::cout << "Название: " << title << "\n";
        std::cout << "Год издания: " << year << "\n";
        std::cout << "Авторы: ";

        // Более безопасный способ вывода авторов
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
            std::cout << "Ошибка открытия файла!\n";
            return;
        }

        Book book;
        std::string line;
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

        std::cout << "Загружено " << books.size() << " книг.\n";
    }

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Ошибка сохранения файла!\n";
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
        std::cout << "Введите номер УДК: ";
        std::cin >> book.udcNumber;
        std::cin.ignore();

        std::cout << "Введите название книги: ";
        std::getline(std::cin, book.title);

        std::cout << "Введите год издания: ";
        std::cin >> book.year;
        std::cin.ignore();

        int authorCount;
        std::cout << "Введите количество авторов: ";
        std::cin >> authorCount;
        std::cin.ignore();

        for (int i = 0; i < authorCount; ++i) {
            Author author;
            std::cout << "Автор " << i + 1 << ":\n";
            std::cout << "Фамилия: ";
            std::getline(std::cin, author.surname);
            std::cout << "Имя: ";
            std::getline(std::cin, author.name);
            std::cout << "Отчество: ";
            std::getline(std::cin, author.patronymic);
            book.authors.insert(author);
        }

        books.insert(book);
        std::cout << "Книга добавлена.\n";
    }

    void removeBook() {
        std::string title;
        std::cout << "Введите название книги для удаления: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it != books.end()) {
            books.erase(it);
            std::cout << "Книга удалена.\n";
        } else {
            std::cout << "Книга не найдена.\n";
        }
    }

    void searchByTitle() {
        std::string title;
        std::cout << "Введите название для поиска: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it != books.end()) {
            it->print();
        } else {
            std::cout << "Книга не найдена.\n";
        }
    }

    void searchByAuthor() {
        Author author;
        std::cout << "Введите фамилию автора: ";
        std::getline(std::cin, author.surname);
        std::cout << "Введите имя автора: ";
        std::getline(std::cin, author.name);
        std::cout << "Введите отчество автора: ";
        std::getline(std::cin, author.patronymic);

        std::cout << "Книги автора " << author.toString() << ":\n";
        bool found = false;

        for (const auto& book : books) {
            if (book.authors.find(author) != book.authors.end()) {
                book.print();
                found = true;
            }
        }

        if (!found) {
            std::cout << "Книги данного автора не найдены.\n";
        }
    }

    void addAuthorToBook() {
        std::string title;
        std::cout << "Введите название книги: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it == books.end()) {
            std::cout << "Книга не найдена.\n";
            return;
        }

        Book modifiedBook = *it;
        books.erase(it);

        Author author;
        std::cout << "Введите фамилию нового автора: ";
        std::getline(std::cin, author.surname);
        std::cout << "Введите имя: ";
        std::getline(std::cin, author.name);
        std::cout << "Введите отчество: ";
        std::getline(std::cin, author.patronymic);

        if (modifiedBook.authors.find(author) != modifiedBook.authors.end()) {
            std::cout << "Этот автор уже есть в списке.\n";
            books.insert(modifiedBook);
            return;
        }

        modifiedBook.authors.insert(author);
        books.insert(modifiedBook);
        std::cout << "Автор добавлен.\n";
    }

    void removeAuthorFromBook() {
        std::string title;
        std::cout << "Введите название книги: ";
        std::getline(std::cin, title);

        auto it = findBookByTitle(title);
        if (it == books.end()) {
            std::cout << "Книга не найдена.\n";
            return;
        }

        Book modifiedBook = *it;
        books.erase(it);

        Author author;
        std::cout << "Введите фамилию автора для удаления: ";
        std::getline(std::cin, author.surname);
        std::cout << "Введите имя: ";
        std::getline(std::cin, author.name);
        std::cout << "Введите отчество: ";
        std::getline(std::cin, author.patronymic);

        auto authorIt = modifiedBook.authors.find(author);
        if (authorIt == modifiedBook.authors.end()) {
            std::cout << "Автор не найден в списке.\n";
            books.insert(modifiedBook);
            return;
        }

        modifiedBook.authors.erase(authorIt);

        if (modifiedBook.authors.empty()) {
            std::cout << "Удален последний автор. Книга будет удалена из библиотеки.\n";
        } else {
            books.insert(modifiedBook);
            std::cout << "Автор удален.\n";
        }
    }

    void displayAll() {
        std::cout << "\nВсего книг в библиотеке: " << books.size() << "\n";
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
    std::cout << "\n=== Меню библиотеки ===\n";
    std::cout << "1. Загрузить данные из файла\n";
    std::cout << "2. Сохранить данные в файл\n";
    std::cout << "3. Добавить книгу\n";
    std::cout << "4. Удалить книгу\n";
    std::cout << "5. Поиск книги по названию\n";
    std::cout << "6. Поиск книг по автору\n";
    std::cout << "7. Добавить автора к книге\n";
    std::cout << "8. Удалить автора из книги\n";
    std::cout << "9. Показать все книги\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
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
                std::cout << "Введите имя файла: ";
                std::getline(std::cin, filename);
                library.loadFromFile(filename);
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Введите имя файла для сохранения: ";
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
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}
