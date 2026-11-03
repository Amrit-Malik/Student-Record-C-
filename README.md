# Student Record and Result Management System

## Project Overview

This project is a console-based Student Record and Result Management System developed using the C programming language.

The program provides a menu-driven interface for storing and managing student details and academic results. It includes features for searching, deleting, CGPA calculation, year-wise performance analysis, sorting, and academic recommendations.

## Student Details
- Name: Amrit Malik
- SAP ID: 590032657
- Programming Language: C
- Project Type: Console-Based Application

## Features

1. Add a student record
2. Search for a student using SAP ID
3. Display all student records
4. Delete an individual student record
5. Calculate and display CGPA
6. Calculate year-wise average CGPA
7. Display students in increasing order of SAP ID
8. Display students in alphabetical order of Name
9. Academic Advisor based on CGPA

## Student Information Stored

Each student record contains:

- SAP ID
- Roll Number
- Name
- Phone Number
- Email ID
- Year
- Current Semester
- SGPA values for completed semesters

## CGPA Calculation

CGPA is calculated by taking the average of the available SGPA values.

For example:

- Semester 1 SGPA: 8.0
- Semester 2 SGPA: 9.0
- Semester 3 SGPA: 7.0

CGPA = (8.0 + 9.0 + 7.0) / 3 = 8.00

## Academic Advisor

The Academic Advisor provides recommendations according to the student's CGPA.

| CGPA Range | Recommendation |
|---|---|
| CGPA >= 9.0 | Excellent Performance |
| CGPA >= 7.5 and < 9.0 | Good Performance |
| CGPA >= 6.0 and < 7.5 | Needs Improvement |
| CGPA < 6.0 | Requires Immediate Attention |

The recommendation logic is implemented using C `if-else` statements.

## Technologies Used

- C Programming Language
- GCC Compiler
- Visual Studio Code
- Git
- GitHub

## Project Structure

```text
Student-Record-C-/
├── 590032657.c
├── README.md
├── AI_USAGE_LOG.md
└── tests/
    ├── sample_input.txt
    └── sample_output.txt