# **Push Swap - 42 School project**
### **Project outline**
This project challenges you to develop an efficient sorting algorithm to arrange a set of integers using a limited set of instructions while minimizing the number of operations. The program takes an unsorted list of integers and sort them using two stacks, Stack A and Stack B, while adhering to a specific set of instructions.

## **Sorting algorithms** 
Sorting algorithms are designed to optimize the arrangement of data, and their performance is measured in terms of time and space complexity, making them crucial tools in various applications. Here are the most common ones used for this project:

**Radix Sort:**
Radix Sort is a non-comparative integer sorting algorithm that has a time complexity of O(n * k), where 'n' is the number of elements and 'k' is the number of digits or bits in the data. It groups elements based on their digit values, performing multiple passes to achieve the final sorted order.

**Insertion Sort:**
Insertion Sort is a simple sorting algorithm with an average-case time complexity of O(n^2). It builds the sorted list one item at a time by inserting each element into its correct position within the already sorted part of the list. While not the fastest for large datasets, it can be very efficient for small lists.

**Merge Sort:**
Merge Sort is a divide-and-conquer sorting algorithm with an average-case time complexity of O(n log n). It divides the input into two halves, sorts them, and then merges them back together. Merge Sort is known for its stability and predictable performance.

**Quick Sort:**
Quick Sort is a highly efficient sorting algorithm with an average-case time complexity of O(n log n). It works by selecting a pivot element and dividing the list into two sub-arrays, which are then recursively sorted. Quick Sort is a popular choice for sorting due to its speed and simplicity.

## **The code**
I choose to start with the turk sort because it made more sense, but ended up doing the radix sort because of the simplicity and the saved up time.
The code is structured in three main parts (not divided by folders) which are:
The allowed set of instructions in the **'actions.c'**, **'allowed_functions_1.c'** and **'allowed_functions_2.c'**
The **'simple_sort.c'** which is the code to sort the cases of 3, 4 and 5 elements in the minimum ammount of instructions allowed
The **'radix_sort.c'** where the algorithm is developed.
There are also three utils files, one for parsing the stack and checking for errors, other for stack utils, like, initializing, printing, freeing and checking if is sorted and the last one for the algorithm mostly with the functions that rotate the stack and index the stack elements from lower to higher.
