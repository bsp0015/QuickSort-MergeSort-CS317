//
//  Quick-MergeSort.cpp
//  Quick-MergeSort-CS317
//
//  Created by Brandon on 2/1/22.
//
#include <iostream>
#include <fstream>
#include <string>

// General functions
bool LESS(double a, double b);
void swap(double* a, double* b);

// QuickSort functions
void quicksort(double A[], int left, int right);
double partition(double A[], int left, int right);

// MergeSort functions
void mergesort(double A[], int left, int right);
void merge(double A[], int left, int mid, int right);

// Decalre counter for # of comparisons
double comparison_counter = 0;

// start program
int main()
{
    using namespace std;
    ifstream inFile; //file containing operations
    ofstream outFile; //file containing output
    string inFileName; //input file external name
    string outFileName; //output file external name

    // ********* QuickSort *********

    /*
     My file names:
        Enter here
    */

    // open the input file
    inFileName = "";                    // Enter your file path here
    inFile.open(inFileName.c_str());

    // open the output file for QuickSort
    outFileName = "";                   // Enter your file path here
    outFile.open(outFileName.c_str());

    //checks to make sure the file opens
    if (!inFile)
    {
        cout << "File not found." << endl;  // let user know file was not found
        exit(2);    // exit code
    }
    
    int size = 0;   // initialize size of array

    inFile >> size; // read in the first line of input file - # of elements

    // declare dynamic array of the read size from the input file
    double* A;
    A = new double[size];

    // Read in the elements and store into array A
    for (int i = 0; i < size; i++)
    {
        inFile >> A[i]; //store each number into the incrementing array
    }

    inFile.close(); // close input file

    // QuickSort
    comparison_counter = 0;     // set comparison counter to 0
    quicksort(A, 0, size - 1);  // call quicksort on array A

    // write the total number of comparisons to the output file
    outFile << "Number of Comparisons for quickSort: \n";
    outFile << comparison_counter << endl;

    // print out the sorted array to the QuickSort output file
    for (int i = 0; i < size; i++)
    {
        outFile << A[i] << "\n";    // output each value in the sorted array onto a new line
    }

    outFile.close();    // close the output file


    // *********** MergeSort *******

    /*
     My file names:
        file path goes here
    */

    // open the input file for MergeSort
    inFileName = "";                    // Enter file path here
    inFile.open(inFileName.c_str());

    // open the output file for MergeSort
    outFileName = "";                   // Enter file path here
    outFile.open(outFileName.c_str());

    inFile >> size; // read in the first line of input file - # of elements

    // declare dynamic array of the read size
    double* B;
    B = new double[size];

    // Read in the elements and store into array A
    for (int i = 0; i < size; i++)
    {
        inFile >> B[i]; // store each number into an incrememnting array
    }

    // MergeSort
    comparison_counter = 0; // reset the comparison counter to 0
    mergesort(B, 0, size-1);   // call MergeSort

    // print the number of comparison of MergeSort to the output file
    outFile << "Number of Comparisons for mergesort: \n";
    outFile << comparison_counter << endl;

    // print out the sorted array to the MergeSort output file
    for (int i = 0; i < size; i++)
    {
        outFile << B[i] << "\n";    // output each element of the sorted array onto a new line
    }

    outFile.close(); // close the output file


    // End program
    return 0;
}


// ***** QuickSort Functions *****

// QuickSort main function
void quicksort(double A[], int left, int right)
{
    if (left < right) // if the left index is less than the right index
    {
        int pivot = partition(A, left, right); // create pivot point
        quicksort(A, left, pivot - 1);  // recursive call on first half
        quicksort(A, pivot + 1, right); // recursive call on second half
    }

    // end function
    return;
}

// partition function for quicksort
double partition(double A[], int left, int right)
{
    int i = left;  // index of smaller part, left side
    int pivot = A[right];   // set pivot point to the value of the right side

    for (int k = left; k < right; k++)     // while the left index is less than the right
    {
        if (LESS(A[k], pivot) || (!LESS(A[k], pivot) && !LESS(pivot, A[k]))) // check if the value in said index is less than or equal to the pivot value
        {
            swap(&A[i], &A[k]);     // swap the smaller and larger elements
            i++;    // increment the index of the smaller portion
        }
    }

    swap(&A[i], &A[right]);     // swap the next element and the right element

    return (i); // return the index of the left indec to set the pivot point in the array
}


// ***** MergeSort Functions *****

// Main mergsort function
void mergesort(double A[], int left, int right)
{
    if (left < right)   // if the left index is less than the right index
    {
        int temp = right - left;
        int m = left + temp / 2; // create mid point
        
        mergesort(A, left, m);      // recursive call the left array
        mergesort(A, m + 1, right); // recursive call the right array
        merge(A, left, m, right);   // merge the two arrays together
    }
}

// merge function used for mergesort
void merge(double A[], int left, int mid, int right)
{
    // declare the initial indexes for the left and right arrays as well as the merged array
    int posLeftArr = 0;
    int posRightArr = 0;
    int posA = left;

    // find sizes of each new array that will be created
    double sizeLeftArr = mid - left + 1;  // find the size of the left array
    double sizeRightArr = right - mid;     // find the size of the right array

    // create two arrays
    double* leftArr;                   // create an array for the left side
    leftArr = new double[sizeLeftArr];

    double* rightArr;                   // create an array for the right side
    rightArr = new double[sizeRightArr];

    // fill the newly created arrays
    for (int i = 0; i < sizeLeftArr; i++) // put data into left  array from original array
    {
        leftArr[i] = A[left + i];   // incrememnt through array starting at the far left of the array
    }

    for (int i = 0; i < sizeRightArr; i++) // put data into right array from original array
    {
        rightArr[i] = A[mid + 1 + i];   // increment throguh array starting at the left of the midpoint
    }

    while (posLeftArr < sizeLeftArr && posRightArr < sizeRightArr)  // while both indexes are less then their respective max sizes
    {
        if (LESS(leftArr[posLeftArr], rightArr[posRightArr])) // if the value in the left array is less than the value in the right array
        {
            A[posA] = leftArr[posLeftArr]; // set merge array to the value of the left array element
            posLeftArr++;  // increment the index of left array
        }
        else
        {
            A[posA] = rightArr[posRightArr]; // set merge array to the value of the right array element
            posRightArr++;  // increment the index of the right array
        }
        posA++;  // increment the index of the merge array
    }

    // merge rest of elements of left array
    while (posLeftArr < sizeLeftArr) // while the index of the left array is less than its max size
    {
        A[posA] = leftArr[posLeftArr]; // set the merge array to the value of the left array element
        posA++;  // increment the index of the merge array
        posLeftArr++;  // increment the index of the left array
    }

    // merge rest of elements of right array
    while (posRightArr < sizeRightArr)
    {
        A[posA] = rightArr[posRightArr]; // set the merge array to the valye of the right array element
        posA++;  // increment the index of the merge array
        posRightArr++;  // increment the index of the right array
    }
}


// ***** General Functions *****

// swap function to switch two elements of an array
void swap(double* a, double* b)
{
    double tmp = *a;   // set temp value to the left value
    *a = *b;    // set left value equal to the right value
    *b = tmp;  // set right value equal to the original left value
}

// function to compare to elements of an array and decide if they are less than or not
bool LESS(double a, double b)
{
    comparison_counter++; // increase comparison counter since it was called

    if (a < b)  // if the left element is less than the right
    {
        return true;
    }
    else {
        return false;
    }
}
