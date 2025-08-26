# Directory-Scanner
Multithreaded C++ application for scanning directories, processing .txt and .csv files in parallel, aggregating data, and generating customizable reports. Demonstrates advanced C++ architecture, STL, multithreading, and file I/O.

# Overview
This project is a multithreaded C++ application that scans a directory for `.txt` and `.csv` files, distributes them across worker threads for processing, aggregates the extracted data, and allows the user to generate customizable reports.

It is designed with scalable architecture, efficient resource management, and modular components to demonstrate clean, production‑ready C++ code.

---

# Features
- Directory scanning for `.txt` and `.csv` files
- Multithreaded processing — each thread performs specific tasks on assigned files
- Parallel directory scanning and file processing
- Data aggregation from CSV files with user‑selected fields
- Report generation in text or CSV format
- Configurable output — user chooses which data to include
- Cross‑platform (tested on macOS and Linux; adaptable for Windows)

---

#Technologies Used
- C++17
- STL (`std::thread`, `std::filesystem`, `std::mutex`, etc.)
- OOP with SOLID
- CMake for build configuration
- RAII and smart pointers for safe memory management

---

