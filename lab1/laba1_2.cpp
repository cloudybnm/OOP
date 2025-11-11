#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

enum class BookType { Fiction, Technical };

class Book {
public:
    std::string author, title;
    BookType type;
    Book(const std::string& a, const std::string& t, BookType tp) : author(a), title(t), type(tp) {
        if (a.empty() || t.empty()) throw std::invalid_argument("Author and title must not be empty");
    }
};

class Library {
    std::vector<Book*> books;
public:
    void addBook(Book* b) { books.push_back(b); }
    void countBooksSwitch() {
        int f = 0, t = 0;
        for (auto b : books) switch (b->type) { case BookType::Fiction: f++; break; case BookType::Technical: t++; break; }
        std::cout << "Fiction: " << f << " | Technical: " << t << std::endl;
    }
    ~Library() { for (auto b : books) delete b; }
};

int main() {
    Library l;
    l.addBook(new Book("Достоевский", "Преступление и наказание", BookType::Fiction));
    l.addBook(new Book("Ньютон", "Математические начала", BookType::Technical));
    l.countBooksSwitch();
    return 0;
}