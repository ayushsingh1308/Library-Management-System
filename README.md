# Library Management System 📚

A console-based Library Management System developed in C++ that helps manage library books efficiently. The project uses file handling to store book records permanently and provides basic library operations through a menu-driven interface.

## 🚀 Features

- Add New Books
- Display All Books
- Search Books by Title or Author
- Issue Books
- Return Books
- File-Based Data Storage
- Simple Console Interface

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling (fstream)
- Functions
- Conditional Statements
- Loops

## 📂 Project Structure

```text
Library-Management-System/
│
├── library.cpp
├── library.txt
└── README.md
```

## ▶️ How to Compile and Run

### Compile

```bash
g++ library.cpp -o library
```

### Run

Windows:

```bash
library.exe
```

Linux/Mac:

```bash
./library
```

## 📖 Menu Options

```text
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit
```

## 📋 Book Details Stored

Each book record contains:

- Book ID
- Book Title
- Author Name
- Book Status (Available/Issued)

## 💡 Sample Usage

### Add a Book

```text
Enter Book ID: 101
Enter Book Title: Data Structures
Enter Author Name: Mark Allen Weiss
```

### Search a Book

```text
Enter Book Title or Author: Data Structures
```

### Issue a Book

```text
Enter Book ID to Issue: 101
Book Issued Successfully!
```

### Return a Book

```text
Enter Book ID to Return: 101
Book Returned Successfully!
```

## 🎯 Concepts Demonstrated

- Classes and Objects
- File Handling
- CRUD Operations
- Search Functionality
- Data Persistence
- Menu-Driven Programming

## 🔮 Future Enhancements

- User Authentication
- Student Management Module
- Fine Calculation System
- Book Deletion Feature
- MySQL Database Integration
- GUI Version using Qt or Java Swing
- Borrowing History Tracking

## 👨‍💻 Author

**Ayush Singh**  
B.Tech Computer Science & Engineering

## 📜 License

This project is open-source and available for educational and learning purposes.

⭐ If you found this project useful, don't forget to star the repository!
