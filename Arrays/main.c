#include <stdio.h>
#include <stdlib.h>

// Defining an ARRAY ADT
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