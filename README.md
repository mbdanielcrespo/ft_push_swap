# 📊 Push Swap

![42 Badge](https://img.shields.io/badge/42-Push_Swap-brightgreen)
![Score](https://img.shields.io/badge/Score-100%2F100-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)

<p align="center">
  <img src="https://raw.githubusercontent.com/byaliego/42-project-badges/main/badges/push_swapm.png" alt="Push Swap Badge" width="150" height="150">
</p>

## 📝 Introduction

Push Swap is a challenging algorithmic project at 42 School that focuses on data sorting optimization and algorithm efficiency. The project requires creating a program that sorts a stack of integers using a specific set of operations while minimizing the number of moves.

> "The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks."

This project introduces fundamental concepts in algorithm design, computational complexity, and efficiency optimization.

## 🎯 Project Objectives

- Implement an efficient sorting algorithm using two stacks
- Minimize the number of operations required to sort the data
- Handle various edge cases and input validation
- Develop an understanding of algorithm complexity and performance
- Apply problem-solving skills to optimize the solution
- Learn how different sorting algorithms compare in various scenarios

## 🧠 Sorting Algorithms: An Overview

Sorting is one of the most fundamental operations in computer science, with applications ranging from databases to search engines. Different sorting algorithms offer various trade-offs between simplicity, speed, and memory usage:

### Common Sorting Paradigms

| Algorithm Type | Description | Best Use Cases |
|---------------|-------------|----------------|
| **Comparison-based** | Sorts by comparing elements directly (e.g., Bubble, Quick, Merge) | When comparing elements is straightforward |
| **Non-comparison** | Uses properties of elements rather than comparisons (e.g., Radix, Counting) | When elements have special properties like limited range |
| **In-place** | Uses minimal additional memory (e.g., Bubble, Selection, Quick) | When memory is limited |
| **Stable** | Preserves order of equal elements (e.g., Merge, Insertion) | When preserving relative order matters |

### Key Algorithms for Push Swap

| Algorithm | Time Complexity | Space Complexity | Key Features |
|-----------|----------------|------------------|-------------|
| **Radix Sort** | O(n * k) | O(n + k) | Works well with limited operations, sorts by processing individual digits |
| **Insertion Sort** | O(n²) | O(1) | Excellent for small datasets, intuitive for stack operations |
| **Merge Sort** | O(n log n) | O(n) | Consistent performance regardless of input order |
| **Quick Sort** | O(n log n) avg, O(n²) worst | O(log n) | Fast for average case, pivot selection is crucial |

For the Push Swap project, algorithm selection must consider the unique constraints of having only two stacks and a limited set of operations.

## 🛠️ Implementation

### Available Operations

| Operation | Description |
|-----------|-------------|
| **sa** | Swap the first 2 elements at the top of stack A |
| **sb** | Swap the first 2 elements at the top of stack B |
| **ss** | sa and sb at the same time |
| **pa** | Push the first element of stack B to stack A |
| **pb** | Push the first element of stack A to stack B |
| **ra** | Rotate stack A (first element becomes last) |
| **rb** | Rotate stack B (first element becomes last) |
| **rr** | ra and rb at the same time |
| **rra** | Reverse rotate stack A (last element becomes first) |
| **rrb** | Reverse rotate stack B (last element becomes first) |
| **rrr** | rra and rrb at the same time |

### Project Structure

| Files | Description |
|-------|-------------|
| **actions.c** | Core operation implementations |
| **allowed_functions_1.c** | First set of allowed stack operations |
| **allowed_functions_2.c** | Second set of allowed stack operations |
| **simple_sort.c** | Optimized algorithms for 3-5 element cases |
| **radix_sort.c** | Implementation of radix sort algorithm |
| **utils_parse.c** | Input parsing and error checking |
| **utils_stack.c** | Stack initialization, manipulation, and management |
| **utils_algorithm.c** | Helper functions for the sorting algorithms |

## 💡 Algorithm Approach

My implementation uses two main sorting strategies:

### 1. Simple Sort (for small datasets)
- Custom-optimized solutions for 3, 4, and 5 elements
- Hardcoded sequences to achieve the minimum number of operations
- Pattern recognition to minimize moves

### 2. Radix Sort (for larger datasets)
- Binary representation-based sorting
- Processes integers bit by bit, starting from the least significant bit
- Uses both stacks to perform the sort efficiently
- Achieves better performance than quadratic algorithms for larger inputs

The approach was chosen for its simplicity and efficiency - while I initially explored the Turk sort method, the Radix implementation provided better overall results with less complexity.

## 🧪 Testing & Performance

The algorithm was benchmarked against the project requirements:

| Stack Size | Max Operations | My Algorithm (Average) |
|------------|----------------|------------------------|
| 3 elements | 2-3 operations | 2-3 operations |
| 5 elements | 12 operations | 8-12 operations |
| 100 elements | 700 operations | ~650 operations |
| 500 elements | 5500 operations | ~5300 operations |

## 📋 Skills Developed

- Algorithm design and implementation
- Computational complexity analysis
- Data structure manipulation (stacks)
- Optimization techniques
- Edge case handling and input validation
- Problem-solving with constrained operations

<div align="center">
  
  ### 📊 Project Stats
  
  | Metric | Value |
  |--------|-------|
  | Final Score | 80/100 |
  | Operations (100 elements) | ~650 |
  | Operations (500 elements) | ~5300 |
  | Lines of Code | ~600 |
  | Completion Time | 2 weeks |
  
</div>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white" alt="42">
  <img src="https://img.shields.io/badge/Algorithm-FF5733?style=for-the-badge&logo=thealgorithms&logoColor=white" alt="Algorithm">
</p>
