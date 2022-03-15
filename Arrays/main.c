#include <stdio.h>
#include <stdlib.h>

// Defining an ARRAY ADT
// This kind of implementation utilizes Arrays as ADT
struct Array
{
    int *A;

    // We can use this two properties for increasing the size of our array
    int size;
    int length;

    // If length is already greater or equal then size, we double the size of our array
};

// Prototypes
void Display(struct Array);
void Append(struct Array *, int);
void Insert(struct Array *, int, int);
int Delete(struct Array *, int);
int LinearSearch(struct Array *, int);
void Swap(int *, int *);
int BinarySearch(struct Array, int);
int recursiveBinarySearch(struct Array, int, int, int);
int Get(struct Array);
void Set(struct Array *, int, int);
int Max(struct Array);
int Min(struct Array);
int Sum(struct Array);
float Average(struct Array);
void Reverse(struct Array *);
void ReverseTwo(struct Array *);
void Shift(struct Array *);
void Rotation(struct Array *);

int main()
{
    // Declaring a struct Array
    struct Array arr;
    printf("Enter size an array");

    // Setting the size of our arrayy
    scanf("%d", &arr.size);

    // Initializing the array in our heap
    arr.A = (int *)malloc(arr.size * sizeof(int));

    // Set the length to 0 since we still don't have any elements
    arr.length = 0;

    // APPENDING ELEMENTS TO OUR ARRAY
    int n, i;

    printf("Enter number of numbers> ");
    scanf("%d", &n);

    printf("Enter all elements\n");
    for (i = 0; i < n; i++)
    {
        // Inserting elements to our array
        scanf("%d", &arr.A[i]);

        // Increment our arr.length
        arr.length++;
    }

    // Append elements to our array
    Append(&arr, 9);

    // Inserting elements to our array
    Insert(&arr, 3, 0);

    // Deleting an element in our array
    printf("Item deleted: %d\n", Delete(&arr, 2));

    // Searching for an element in our array using LinearSearch
    printf("Item found: %d\n", LinearSearch(&arr, 5));

    // Displaying the values of our arrays
    Display(arr);

    return 0;
}

// Use this to display our arrays
void Display(struct Array arr)
{
    int i;
    printf("Elements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d\n", arr.A[i]);
}

// Appending an element at the end of an array
void Append(struct Array *arr, int x)
{
    // Using the address so we can directly use a pointer
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

// Inserting an element in an array at a given index
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
}

// Deleting an element from an array
// This returns the deleted element
int Delete(struct Array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            // Improving Linear Search
            // Transposition
            swap(&arr->A[i], &arr->A[i - 1]);

            // Move to HEAD
            // swap(&arr -> A[i], &arr -> A[0])
            return i;
        }
    }
    return -1;
}

// Utilizing Parameter Passing to swap
void swap(int *x, int *y)
{

    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

// Binary Search Implementation use only if you have a sorted array
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

// Recursive Binary Search Implementation. ONLY USE THIS ON SORTED ARRAYS
int recursiveBinarySearch(struct Array arr, int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return recursiveBinarySearch(arr, l, mid - 1, key);
        else
            return recursiveBinarySearch(arr, mid + 1, h, key);
    }
    return -1;
}

// An array method that we can use to get the value of an array at a given index
int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// An array method that we can use to set the value of an array at a given index to x
void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

// An array method that we can use to find the max value at a given array
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (max < arr.A[i])
            max = arr.A[i];
    }
    return max;
}

// An array method that we can use to find the minimum value of an array
int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}

// Use this function to find the sum of all elements of an array
int Sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return sum;
}

// Use this function to find the average of all elements in an array
float Average(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return (float)sum / arr.length;
}

// Use this method to reverse an array using the first method
void Reverse(struct Array *arr)
{
    // First Method
    int *B;
    int i, j;

    B = (int *)malloc(sizeof(int) * (arr->length - 1));

    for (i = arr->length - 1, j = 0; i > 0; i--, j++)
        B[j] = arr->A[i];

    for (i = 0; i > arr->length; i++)
        arr->A[i] = B[i];
}

// Use this method to reverse an array using the second method
void ReverseTwo(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        Swap(arr->A[i], arr->A[j]);
}

// Use this method to shift an array
void Shift(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
}

// Use this method to rotate an array
void Rotate(struct Array *arr)
{
    int firstElement = arr->A[0];
    for (int i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];

    arr->A[arr->length - 1] = firstElement;
}