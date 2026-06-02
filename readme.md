# 🍽️ Online Food Management System (C Programming Project)

## 📌 Overview

The Online Food Management System is a console-based application developed in the C programming language. In this project, I designed and implemented a complete food ordering simulation system that replicates the core features of real-world food delivery platforms like restaurant management, menu browsing, and order placement.

I built this system to strengthen my understanding of Data Structures and Algorithms (DSA) and to apply theoretical concepts into a practical working application. The system is fully menu-driven and operates through two main modules: Restaurant Mode and Customer Mode.

This project focuses on efficient data handling using structures, sorting, and searching techniques, making it a strong example of applied DSA in a real-world scenario.

---

## 🎯 Objective of the Project

The main objective of this project was:

- To design a structured food ordering system using C
- To simulate real-world restaurant and customer interactions
- To apply core DSA concepts like sorting and searching
- To manage complex data using arrays and structures
- To build a menu-driven system with multiple functionalities

I personally aimed to build something that goes beyond basic academic programs and demonstrates real application-level logic.

---

## 🏗️ System Design

The system is divided into two major modules:

### 1. Restaurant Mode (Admin Side)

In this module, I implemented functionalities for managing restaurants and their menus. The admin can:

- Add new restaurants with name, address, and area
- Delete existing restaurants using name and address
- Add food items to restaurant menus
- Add special items for promotions
- Set an "Item of the Day"
- Maintain sorted restaurant and menu lists

I made sure that all restaurant and food data is stored in structured formats using nested structures for better organization.

---

### 2. Customer Mode (User Side)

This module is designed for users who want to explore restaurants and place orders. I implemented multiple features such as:

- Searching food items across all restaurants
- Checking availability of items
- Finding the restaurant with minimum delivery time
- Viewing menus sorted by name
- Viewing menus sorted by price
- Exploring restaurants by area
- Placing multi-item and multi-restaurant orders

I designed this module to simulate a real food delivery experience where users can interact with multiple restaurants in a single session.

---

## 🍔 Key Features Implemented

### 🔎 Search Features
- I implemented binary search to quickly find food items in sorted arrays.
- Users can check whether a specific item is available in any restaurant.
- The system also finds the minimum delivery time for a selected item.

---

### 🍽️ Menu Management
- I designed a system to store regular items, special items, and item of the day separately.
- All items are automatically inserted in sorted order using insertion logic.
- Users can view full menus in alphabetical order or sorted by price.

---

### 📦 Order Management System
- I implemented a complete ordering system where users can place multiple items in one order.
- Orders can be placed from multiple restaurants at the same time.
- Each order is assigned a unique order ID.
- Customer details like name, phone number, and address are stored.

This was one of the most complex parts of the project, and I carefully managed mapping between restaurants and orders.

---

### 📊 Advanced Features
I also added advanced analytical features such as:

- Finding common items across multiple restaurants
- Identifying unique items available in only one restaurant
- Sorting special items across restaurants
- Displaying item of the day by area
- Grouping restaurants based on location

These features required careful use of loops, conditions, and string comparison logic.

---

## 🧠 Data Structures Used

In this project, I used multiple structured data types:

- Structures for restaurant data
- Nested structures for food items
- Arrays of structures for menus and orders
- Character arrays for string handling

I designed these structures to ensure scalability and efficient data handling.

---

## ⚙️ Algorithms Used

### 1. Binary Search
I used binary search to optimize item lookup operations in sorted arrays. This reduced search complexity significantly.

### 2. Insertion Sort
I used insertion logic to maintain sorted order while adding restaurants and food items.

### 3. Merge Sort
I implemented merge sort for:
- Sorting items by price
- Sorting restaurant lists
- Generating ordered outputs for special item lists

These algorithms helped improve efficiency and maintain structured data flow.

---

## 🧩 Program Flow

The overall system flow is:

1. Program starts
2. Predefined restaurants are loaded (KFC, Domino’s, Haldiram’s)
3. Main menu is displayed
4. User selects:
   - Customer Mode
   - Restaurant Mode
   - View All
5. Based on selection:
   - Data is inserted
   - Data is searched
   - Data is sorted
   - Orders are processed

I designed the flow to be simple and user-friendly while handling complex operations internally.

---

## 🏬 Preloaded Data

I added sample restaurants to make the system ready for demonstration:

### KFC
- Burgers
- Chicken Bucket
- Special Items

### Domino’s
- Pizzas
- Garlic Bread
- Special Combos

### Haldiram’s
- Indian Snacks
- Thali Items
- Traditional Dishes

This helps users test the system without manually adding data.

---

## 💡 Challenges I Faced

During development, I faced several challenges such as:

- Managing multiple nested structures
- Handling multi-restaurant orders
- Maintaining sorted data after insertion
- Implementing binary search correctly
- Avoiding memory and indexing errors

I solved these issues by carefully debugging and testing each module individually.

---

## 🚀 Future Improvements

If I extend this project, I would like to add:

- File handling for permanent storage
- Database integration (MySQL)
- Login system for users and restaurants
- Online payment simulation
- GUI version using C++ or web technologies
- Real-time order tracking system

---

## 📌 Conclusion

This Online Food Management System is a complete demonstration of how Data Structures and Algorithms can be applied in real-world applications.

I built this project to strengthen my programming fundamentals and to understand how real systems like food delivery platforms manage complex data efficiently.

Through this project, I learned how to design scalable systems, handle structured data, and implement efficient searching and sorting techniques in C.

Overall, this project reflects my understanding of DSA concepts and my ability to apply them in a practical and structured way.