#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Forward declaration of the Library class
class Library;

// Class to represent a Member (both Member and Librarian inherit from this base class)
class Member {
public:
    string name;
    int id;
    string email;
    string role;
    vector<string> borrowedBooks;
    Member() : name(""), id(0), email(""), role("") {}
    // Constructor to initialize member data
    Member(string name, int id, string email, string role) 
        : name(name), id(id), email(email), role(role) {}

    // Member function to input member data
    void inputMemberData(const string& role);
    
    // Function to display member data
    void display() const;

    // Borrow a book
    void borrowBook(const string& bookName);

    // Return a book
    void returnBook(const string& bookName);
};

// Class to represent a Book
class Book {
public:
    string title;
    string author;
    bool isAvailable;

    // Constructor
    Book(string t, string a, bool available = true) : title(t), author(a), isAvailable(available) {}

    // Display Book information
    void display() const;
};

// Class to represent a Library
class Library {
public:
    vector<Member> members;
    vector<Book> books;

    // Method to register a new Member or Librarian
    void registerUser(Member& member);

    // Method to login as a Member
    bool loginAsMember(int id, const string& email);

    // Method to login as a Librarian
    bool loginAsLibrarian(int id, const string& email);

    // Method to add a book
    void addBook(const string& title, const string& author);

    // Method to display all books
    void displayBooks() const;

    // Method to issue a book to a member
    bool issueBook(Member& member, const string& bookTitle);

    // Method to return a book to the library
    bool returnBook(Member& member, const string& bookTitle);

    // Method to recommend books based on borrowing trends
    void recommendBooks(Member& member);

    // Helper methods to load data from files
    void loadBooks();
    void loadMembers();
    void loadLibrarians();

    // Helper methods to save data to files
    void saveBooks();
    void saveMembers();
    void saveLibrarians();
    void saveBorrowedBooks();
};

#endif // LIBRARY_H
