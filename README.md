# FoC — Fundamentals of Computing

A C programming project (Fundamentals of Computing) that implements a menu-driven application covering two main topics: **Prime Numbers** and **Image Processing**. Prime number features include primality checking and the Sieve of Eratosthenes algorithm. Image processing features include vertical flipping and clockwise rotation of pixel-based images stored in files, using 2D arrays and file I/O in C.

## Features

### Prime Numbers
- Check if a number is prime
- List all prime numbers from 1 to N (trial division)
- List all prime numbers from 1 to N using the **Sieve of Eratosthenes**

### Image Processing
- **Flip image vertically** — mirrors the image upside down
- **Rotate image clockwise** — rotates the image 90° to the right
- Images are read from and written to `image.in` files using file I/O

## How to Run

1. Compile the program:
```bash
gcc code.c -o program -lm
```
2. Run:
```bash
./program
```
3. Follow the menu:
```
1. Check if a number is prime
2. List all primes from 1 to N
3. Sieve of Eratosthenes
4. Flip image vertically
5. Rotate image clockwise
6. Exit
```

## Project Structure

```
FoC/
├── code.c          # Main C source file
├── flow.drawio.pdf # Flowchart diagram
├── TASK8[1].docx   # Task description
├── make up.docx    # Project documentation
└── README.md
```

## Technologies

`C` · `File I/O` · `2D Arrays` · `Sieve of Eratosthenes` · `Image Processing`

## Author

**Omar Abuhassan**
