# Course Management System (CMS)

A simple C++ Course Management System for managing students, teachers, courses, enrollments, comments, and posts.

## Features

- Manage students and teachers
- Add, edit, and remove courses
- Enroll students in courses and sections
- Post and comment functionality
- Custom string and date handling

## Project Structure

- `student.cpp`, `student.h` – Student management
- `teacher.cpp`, `teacher.h` – Teacher management
- `course.cpp`, `course.h` – Course management
- `section.cpp`, `section.h` – Section management
- `enrollcourses.cpp`, `enrollcourses.h` – Enrollment logic
- `post.cpp`, `post.h` – Post functionality
- `comment.cpp`, `comment.h` – Comment functionality
- `address.cpp`, `address.h` – Address handling
- `date.cpp`, `date.h` – Date handling
- `Mystr.cpp`, `Mystr.h` – Custom string class
- `testing.cpp` – Main file for testing the system

## How to Build

1. Make sure you have a C++ compiler (like g++, clang++) installed.
2. Compile all `.cpp` files together. Example using g++:

    ```sh
    g++ *.cpp -o cms
    ```

3. Run the executable:

    ```sh
    ./cms
    ```

   On Windows, run:

    ```sh
    .\cms.exe
    ```

## Usage

- The program runs in the console.
- Follow the on-screen instructions to manage students, teachers, courses, posts, and comments.

## License

This project is for educational
