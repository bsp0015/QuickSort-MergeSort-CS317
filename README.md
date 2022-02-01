# QuickSort-MergeSort-CS317
This was a program to implement quick sort and merge sort given an input file for my CS 317 class.

Completed: 10-13-2021

## Assignment

### INSTRUCTIONS: 
You are writing a program. It must compile, execute and produce the 
desired output. Use C/C++, Java. 

### OBJECTIVE:  
Write a program to sort a given array A[n] by: 
 1. quicksort  
 2. mergesort 
 
### PROCESSING:  
1. Sort the given array using quicksort and output the sorted array.  
2. Sort the given array using mergesort and output the sorted array. 
---
Your program must have the following function clearly identified and implemented:  

- Comparison function - to compare an array element to another array element: - LESS(a, 
b) : if (a < b) return true, else return false.  

Note that all other operators (>, >=, <=, ==, !=) can be computed by making appropriate 
calls to the above function.  

The above function must increment a counter 'comparison_count' (this will be needed 
for output).  

Obviously, one of your goals is to minimize the total number of array element 
comparisons. ABSOLUTELY NO "array element" comparisons outside of this function. 
<br>
- The program should output the sorted array and the total number of element 
comparisons taken for each of the sorting methods. 

### INPUT: 
You can assume the elements will be of type 'double'.  

Read the input array from a file named "input.txt". 

This file will have the array elements separated ONLY by "end of line (newline)" 
characters.  

The first line will have the number of elements (integer).  

Thereafter, each line will contain one element of the array (double).  

No other characters will be present in the file. 

For Example: 
- 6 
- 23.65 
- 8.56 
- 10.45 
<br>
Test your program with arrays of size ~10,000 or higher. Note that your program must 
NOT take command line inputs. 

### OUTPUT(S): 
Your program will generate 2 output files:  

<your firstname>_quick.txt:  
- output the sorted array for quicksort (keep same format as the input)  
- output the total number of comparisons taken <your firstname>_merge.txt:  
- output the sorted array for mergesort (keep same format as the input)  
- output the total number of comparisons taken
