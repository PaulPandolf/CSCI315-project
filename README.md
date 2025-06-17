# CSCI315-project

A modular C++ project structured with separate folders for headers and source files. This guide explains how to compile and run the project using `g++` from the terminal.

## 📁 Project Structure

```
CSCI315-project/
├── include/
│   └── CSCI315-project/
│       └── example.h
├── src/
│   ├── main.cpp
│   └── example.cpp
```

## 🛠 Prerequisites

- `g++` (C++17 or higher)
- Unix-like terminal (Linux/macOS/WSL/Git Bash)

Verify installation:

```bash
g++ --version
```

## 🚧 Build Instructions

From the project root, run:

```bash
g++ -std=c++17 -Iinclude -o main src/*.cpp
```

- `-std=c++17`: Use C++17 standard  
- `-Iinclude`: Include headers from `include/`  
- `-o main`: Output binary name  
- `src/*.cpp`: Compile all source files  

## ▶️ Run

```bash
./main
```

## 🧹 Clean Up

```bash
rm main
```

## 📝 Notes

- Headers should be placed under `include/CSCI315-project/` for namespacing.
- Add `.cpp` files to `src/` and they will be compiled automatically by the wildcard.