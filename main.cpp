#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;

public:
    void setBookDetails(string t, string a, string i, bool av) {
        title = t;
        author = a;
        ISBN = i;
        availability = av;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (availability ? "Yes" : "No") << endl;
        cout << "----------------------" << endl;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    void returnBook() {
        availability = true;
        cout << "Book returned successfully." << endl;
    }

    string getISBN() {
        return ISBN;
    }

    bool isAvailable() {
        return availability;
    }
};

int main() {
    Book books[5];

    // Initialising books
    books[0].setBookDetails("Rich Dad Poor Dad", "Robert T. Kiyosaki", "1", true);
    books[1].setBookDetails("The Richest Man in Babylon", "George Samuel Clason
", "2", true);
    books[2].setBookDetails("In The Name of The People", "Bruno Perini", "3", true);
    books[3].setBookDetails("Atomic Habits", "James Clear", "4", true);
    books[4].setBookDetails("Assassin's Creed: Renaissance", "Oliver Bowden", "5", true);

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program ended." << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;

                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                } else {
                    cout << "Book is already borrowed." << endl;
                }

                books[i].displayBookDetails();
                break;
            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    return 0;
}
