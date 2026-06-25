🛍️ ECOM-Store - C++ Console-Based E-Commerce System

A complete terminal-based e-commerce management system built in C++ as my final Programming Fundamentals project.
📌 Project Overview

ECOM-Store is a fully functional console application that simulates an online shopping experience. It allows customers to browse products from an inventory file, add items to a dynamic shopping cart, update quantities, and checkout with order details saved to a file. The system also includes a product management backend for inventory operations.
✨ Features

🛒 Customer Side:

    View available products from inventory

    Add products to cart (dynamic array growth)

    Remove products from cart (dynamic array shrink)

    Update product quantities

    Checkout with order summary

    File-based order storage

🔐 Admin Side:

    Product management

    Inventory file handling

💾 Data Persistence:

    Inventory loaded from Inventory.txt

    Orders saved to UserInfo.txt

    Admin credentials stored in adminpanel.txt

🛠️ Technical Highlights

    Language: C++

    Memory Management: Dynamic allocation with new[]/delete[]

    Pointers: 2D and 3D pointer manipulation (char**, char***)

    File I/O: Reading/writing text files for data persistence

    Data Structures: Dynamic arrays with grow/shrink functionality

    Paradigm: Procedural programming with structured functions

📂 File Structure
text

ECOM-Store/
├── main.cpp           # Entry point and menu system
├── Inventory.txt      # Product database
├── adminpanel.txt     # Admin credentials
├── UserInfo.txt       # Order history
└── README.md          # Project documentation

🚀 How to Run
bash

# Compile
g++ main.cpp -o ecomstore

# Run
./ecomstore

📝 What I Learned

    Dynamic memory management in C++

    File I/O operations

    Pointer manipulation (including triple pointers!)

    Real-world system design

    Debugging complex logic

    Building a complete application from scratch

🏆 Grade & Recognition

This project was developed as part of my Programming Fundamentals course and was completed independently. It demonstrates understanding of core C++ concepts including memory management, file handling, and system design.
