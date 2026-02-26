# 📚 Library Management System (C++)

A console-based Library Management System built using **C++**, implementing core **Object-Oriented Programming (OOP)** principles and **file handling** to ensure persistent data storage.

This project demonstrates structured program design, data consistency management, and practical usage of STL containers.

---

## 🚀 Features

### 📌 Book Management
- ➕ Add new books (with duplicate ID prevention)
- 🗑 Delete books by ID
- 📖 View all stored books

### 🔍 Advanced Search Functionality
Search books using multiple criteria:
- Search by **Book ID**
- Search by **Book Name**
- Search by **Author Name**

### 💾 Persistent Storage
- Uses `ifstream` and `ofstream`
- Automatically loads data at startup
- Rewrites file safely after deletion
- Maintains synchronization between memory (`vector`) and file

---

## 🛠 Technologies & Concepts Used

- **C++**
- **Object-Oriented Programming**
  - Encapsulation
  - Classes & Objects
- **STL**
  - `vector`
- **File Handling**
  - `ifstream`
  - `ofstream`
- Menu-driven system design
- Data validation logic

---

## 📂 Project Structure
```
library-management-system-cpp/
│
├── library_management_system.cpp
├── data.txt
└── README.md
```

---

## 📄 Data File Structure
Structured plain-text format:

```
BookID
BookName
AuthorName
```

### Example:

```
101
Clean Code
Robert C. Martin
102
The Pragmatic Programmer
Andrew Hunt
```

This structure ensures:
- Easy parsing
- Clean data organization
- Reduced risk of file corruption

---

## ▶ How to Run

### 1️⃣ Compile
g++ library_management_system.cpp -o library

### 2️⃣ Run
./library

---

## 🔮 Future Improvements

- Case-insensitive search
- Sorting books (by ID or Name)
- Update/Edit book feature
- Binary file storage
- Header & source file separation
- Database integration
- User authentication system

---

## 📈 Learning Outcomes

This project demonstrates:

- Practical implementation of OOP concepts
- File-based data persistence
- Managing consistency between memory and storage
- Writing modular and maintainable C++ code

---

## 👨‍💻 Author

Om Yadav  
B.Tech CSE Student  
Focused on C++, DSA, and system-level fundamentals
