## Data Structures and Algorithms in C

This repository will be an open-source project exploring the implementation of Data Structures and algorithms in C

#### Table of Contents

- [Arrays](#arrays)
    - [Static Array Implementation Example](#static-array-implementation-example)
  - [Calculating the Address of Elements in an array](#calculating-the-address-of-elements-in-an-array)
    - [Row Major](#row-major)
    - [Column Major](#column-major)
    - [Horner’s Method](#horners-method)
  - [Data on an Array](#data-on-an-array)
  - [Operations on an Array](#operations-on-an-array)
    - [Display](#display)
    - [Append](#append)
    - [Insert](#insert)
    - [Delete](#delete)
    - [Search](#search)
    - [Get](#get)
    - [Set](#set)
    - [Max/Min](#maxmin)
    - [Sum](#sum)
    - [Average](#average)
    - [Reverse](#reverse)
    - [Shift/Rotate](#shiftrotate)
  - [Merging Arrays](#merging-arrays)
    - [Common Operations on Merging](#common-operations-on-merging)
- [Linked List](#linked-list)
  - [Difference with Arrays and Linked Lists](#difference-with-arrays-and-linked-lists)
  - [Methods of Linked Lists](#methods-of-linked-lists)
    - [Traversing a Linked Lists](#traversing-a-linked-lists)
      - [Applications](#applications)
- [Structures](#structures)
  - [Structure Padding](#structure-padding)
- [Pointers](#pointers)
  - [Pointer to Structure](#pointer-to-structure)
- [Functions](#functions)
- [Data Structures](#data-structures)
  - [Physical Data Structures](#physical-data-structures)
    - [Examples](#examples)
  - [Logical Data Structures](#logical-data-structures)
    - [Examples](#examples-1)
- [Abstract Data Type](#abstract-data-type)
  - [List](#list)
    - [Operations](#operations)

# Arrays

Defined as a collection of all data elements with the same data type

> You can check the Arrays directory and go to `main.c` to check the full implementation of the code

### Static Array Implementation Example

```c
// Array Declaration
// <data type> <name of array>;
int numbers[5];
char string[5];

// Array Initiliation
// First Method
int numbers[5]={1,2,3,4,5};
// Second Method
numbers={1,2,3,4,5};
// Third
numbers[0]=1;

// Accessing every elements of an array
for (int i = 0; int <= 5, i++) {
	printf("%d", numbers[i]);
}
```

-   Called a vector variable because it can store a contiguous elements in a single memory

## Calculating the Address of Elements in an array

### Row Major

> For accessing an element at an index `Array[i][j]` with an array with a `m*n` dimension, we can infer that address is equal to `Base address + (i*n +j) * <data size per cell>`

> Formula is derived from left to right.

### Column Major

> For accessing an element at an index `Array[i][j]` with an array with a `m*n` dimension, we can infer that address is equal to `Base address + (j*m + i) * <data size per cell>`

> Formula is derived from right to left.

### Horner’s Method

> Horner's rule for polynomial division is an algorithm used to simplify the process of evaluating a polynomial *f(x)* at a certain value *x = x0* by dividing the polynomial into monomials (polynomials of the 1st degree). Each monomial involves a maximum of one multiplication and one addition. The result obtained from one monomial is added to the result obtained from the next monomial and so forth in an accumulative addition fashion. This division process is also known as synthetic division.

> This method can be used to find the address of an element in an nDimension array

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/81b67c36-3e03-4eee-8a61-69c3d4b06a50/Untitled.png)

## Data on an Array

-   Array Space
    -   Where will the array be initialized either the stack or the heap
-   Size
    -   How many cells of memory will be allocated per array
-   Length
    -   Tells the number of elements in array

## Operations on an Array

### Display

We traverse all elements of the array so we can print it.

```
for (i = 0; i < length of array; i++):
	print(Array at index `i`)
```

### Append

We push an element at the last index of an array

```
Array[length] = x

// Then update our length by adding one
```

### Insert

We push an element at a given index, so we need to shift all elements starting from the index assigned by one cell.

```
for (i=Length; i > index;i--)
	A[i]=A[i-1];
A[index]=element that we want to append;
```

### Delete

We delete an element at a given index so we shift all the succeeding elements

```
x = A[index];

for (i = index; i < Array length - 1; i++)
	A[i]=[A[i+1];
Array length --
```

### Search

To perform a search, elements in an array must be unique

**Linear Search**

In linear search, we ask for a key to be search in an array then we traverse our array one by one

```
for (i = 0; i < length; i++) {
    if (key == Array[i]) return i;
}
return -1;
```

**Ways to improve Linear Search**

-   Transposition
    -   You move an element forward every time it’s searched so that checking it next time will be faster
    ```
    for (i = 0; i < length; i++) {
        if (key == Array[i]) {
            swap(A[i], A[i - 1]);
            return i;
        }
    }
    return -1;
    ```
-   Move to head
    -   Every time an item is search, put it on the head so if we searched for it again then finding it will be one move only.
    ```
    for (i = 0; i < length; i++) {
        if (key == Array[i]) {
            swap(Array[i], Array[0]);
            return i;
        }
    }
    return -1;
    ```

**Binary Search**

To perform binary search, elements of an array must be sorted.

### Get

Use to find the element at a given index

### Set

Replace the value at a given index given x

### Max/Min

Returns either the maximum or minimum value inside an array

```
// We iterate every element of an array
max = A[0];
for (i = 0; i < arr.length; i++)
	if (max < arr[i]) max = arr[i];
return max;

// Checking min element
min = A[0];
for (i = 0; i < arr.length; i++0)
	if (min > arr[1]) min = arr[i];
return min;
```

### Sum

Returns the sum of all array elements

```
total = 0;
for (i = 0; i < arr.length; i++) total = total + arr[i];
return total;
```

### Average

Returns the average of all the elements inside an array

```
total = 0;
for (i = 0; i < arr.length; i++) total = total + arr[i];
return total / arr.length;
```

### Reverse

Use this method to reverse the order of elements on an array

-   First method:
    -   Create an auxiliary array that will be used to store the reverse order of elements on array.
    -   Remove the original array from the memory and set its value to the elements at auxiliary array.
-   Second method:
    -   Swap the first and last array and so on

### Shift/Rotate

**Shift**

Remove the first element then shift all elements to the left

**Rotation**

Remove the first element then shift all elements to the left then put the element at the last index.

## Merging Arrays

Can only be done on sorted arrays. It can only be done by creating a third array

### Common Operations on Merging

-   Append
-   Concat
-   Compare
-   Copy

````

# Linked List
- Arrays have a fix size so we need to increase it everytime our elements exceeds the memory allocated during declaration.
- Arrays are not good when we don't know the exact number of elements we are going to store in memory
- We need to continuously increase our memory size when we are going to put elements


## Difference with Arrays and Linked Lists
- Accessing elements on an array can be done through indexing since they are contiguous

## Methods of Linked Lists
### Traversing a Linked Lists
To traverse a linked list, you need to use another pointer and reinitiliaze its value to the address of the next pointer every time
#### Applications
- Displaying contents of linked lists


# Structures

Is a collection of data members that are related under one name. They could be of a similar type or dissimilar type. We can create

Structures are usually used to temporarily store records, which will be eventually stored in files. It can also be used later when dealing with the more complex data structures that C is capable of using.

```jsx
// Defining a structure
// struct <Name of Structure>
struct Rectangle {
	// declaring data members
	int length;
	int breadth;
}

int main() {
	// declaration
	// struct <Name of Structure> <name of variable>
	struct Rectangle r;

	// you can also do this
	// declaration + initialization
	struct Rectange r = {10,5};

	// changing the value of a member
	r.length=15;

	// you can even create an array of structures
	struct Rectange rectangles[5]={{1,2}...};
}
````

## Structure Padding

Structure padding is a concept in C that adds one or more empty bytes between the memory addresses to align the data in memory.

# Pointers

Are used for accessing heap memory and resources outside of the program memory. It is also used for parameter passing

## Pointer to Structure

# Functions

# Data Structures

Is an arrangement of collected data items so that they can be utilized efficiently together with the operations that can be done for the data. Arrangement of the collected data is done on the main memory.z

## Physical Data Structures

-   It defines how memory is organized in our programs and how it will be allocated in our memory

### Examples

-   Arrays
-   Linked List

## Logical Data Structures

-   It defines how memory will be processed and utilizes Physical Data Structures for representations.
-   It provides concepts for implementation such as relationships, appending, deletion, and possible algorithms to make methods faster

### Examples

-   Stack
    -   Linear
    -   LIFO - Last-in, First-Out
-   Queues
    -   Linear
    -   FIFO - First-in, First-Out
-   Trees
    -   Non-linear
-   Graph
    -   Non-linear
-   Hash Table
    -   Tabular

# Abstract Data Type

**Things to consider**

1. Representation of Data
2. Operation on Data

## List

### Operations

-   Add/Append/Push
    -   use to append element
-   Insert/Add (at a given index)
    -   append at a given index
