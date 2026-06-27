# Expense Tracker Application

## Cross-Language Application Development

### Team Members
- Nikhil Adhikari
- Bishal Adhikari

---

# Project Overview

The Expense Tracker Application is a desktop application developed as part of the Cross-Language Application Development project. The objective is to implement the same application in two different programming languages while maintaining identical functionality and comparing their implementation.

The application allows users to record, manage, search, and calculate personal expenses. Both implementations provide the same core functionality but demonstrate the features and programming styles of Python and C++.

---

# Programming Languages

- Python (Tkinter GUI)
- C++ (Console Application)

---

# Features

The application includes the following features:

- Add Expense
- View Expenses
- Search Expenses
- Delete Expense
- Calculate Total Expenses
- Save expense records
- Load saved expense records
- Input validation
- Error handling

---

# Project Structure

```
ExpenseTracker
│
├── Python/
│   ├── expense_tracker_gui.py
│   ├── expenses.json
│
├── Cpp/
│   ├── expense_tracker_visual_studio.cpp
│   ├── expenses.txt
│
├── Documentation/
│   ├── Deliverable1.pdf
│   ├── Deliverable2.pdf
│
├── Screenshots/
│
└── README.md
```

---

# Python Version

## Requirements

- Python 3.11 or later

## Libraries Used

- tkinter
- json
- os

No external Python libraries are required.

### Running the Python Application

Open a terminal in the Python folder and run:

```bash
python expense_tracker_gui.py
```

The application automatically creates:

```
expenses.json
```

to store expense records.

---

# C++ Version

## Requirements

- Visual Studio 2026 Community
- Desktop Development with C++ workload

### Running the C++ Application

1. Open Visual Studio.
2. Create a Console App (C++) project.
3. Replace the generated source file with:

```
expense_tracker_visual_studio.cpp
```

4. Build and run the project.

The application automatically creates:

```
expenses.txt
```

to store expense records.

---

# Functional Requirements

The application allows users to:

- Add new expenses
- View all expenses
- Search expenses
- Delete expenses
- Calculate total spending
- Save expense records
- Reload saved records

---

# Data Storage

Python implementation:

```
expenses.json
```

C++ implementation:

```
expenses.txt
```

---

# Comparison of Languages

## Python

Advantages

- Simple syntax
- Rapid development
- Easy GUI creation using Tkinter
- Dynamic typing

Disadvantages

- Slower execution
- Less strict type checking

---

## C++

Advantages

- Fast execution
- Strong type checking
- Excellent memory control

Disadvantages

- More complex syntax
- Requires compilation
- Longer development time

---

# Future Improvements

Future versions of the application may include:

- Expense categories with charts
- Monthly reports
- User authentication
- Database integration
- Export to Excel
- Export to PDF
- Graphical statistics
- Cloud synchronization

---

# Testing

The application has been tested for:

- Adding expenses
- Viewing expenses
- Searching expenses
- Calculating totals
- Deleting expenses
- Saving data
- Loading data
- Invalid user input

---

# Author

Cross-Language Application Development Project

Expense Tracker

Python and C++ Implementation