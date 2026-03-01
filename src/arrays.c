#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int serialSearch(int *arr, int N, int num);
void quicksort(int *arr, int lo, int hi);
int pivotPartition(int *arr, int lo, int hi);
void swap(int *a, int *b);
int binarySearch(int *arr, int lo, int hi, int num);
int* mergeWithNewSortedArray(int *arr, int N);
void printArray(int *arr, int N);
void storeToFile(int *arr, int N);
void showMenu(int *arr, int N);
void printMenu();

int main(int argc, char **argv)
{
    int i;
    int N;
    int *arr;

    srand(time(NULL));

    /* Read N */
    printf("Read size of Array (N) : ");
    scanf("%d", &N);

    /* Allocate memory for array */
    arr = (int*) malloc(N * sizeof(int));
    if (!arr)
    {
        printf("Error in allocating heap memory.\n");
        exit(1);
    }

    /* Fill array with random nums [30...50] */
    for (i = 0; i < N; i++)
        *(arr + i) = 30 + rand() % (50 - 30 + 1);

    showMenu(arr, N);

    free(arr);

    return 0;
}

int serialSearch(int *arr, int N, int num)
{
    int i;

    for (i = 0; i < N; i++)
        if (*(arr + i) == num)
            return i;
     
    return -1;
}

int* sortArray(int *copy_arr, int N)
{
    /* Quicksort */
    int lo, hi;

    lo = *copy_arr;
    hi = *(copy_arr + N - 1);

    quicksort(copy_arr, lo, hi);

    return copy_arr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivotPartition(int *arr, int lo, int hi)
{
    int pivot = *(arr + hi);
    int i = lo - 1;
    int j;

    for (j = lo; j < hi; j++)
    {
        if (*(arr + j) <= pivot)
        {
            i++;
            swap(arr + i, arr + j);
        }
    }

    swap(arr + i + 1, arr + hi);
    return i + 1;
}

void quicksort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int p = pivotPartition(arr, lo, hi);

        quicksort(arr, lo, p - 1);
        quicksort(arr, p + 1, hi);
    }
}

int binarySearch(int *arr, int lo, int hi, int num)
{
    int mid;

    if (lo > hi)
        return -1;
    
    mid = lo + (hi - lo) / 2;

    if (*(arr + mid) == num)
        return mid;
    
    if (num < *(arr + mid))
        return binarySearch(arr, lo, mid - 1, num);
    else
        return binarySearch(arr, mid + 1, hi, num);
}

int* mergeWithNewSortedArray(int *arr, int N)
{
    int *arr2;
    int *merged;
    int i, j, k;

    arr2 = (int *) malloc(N * sizeof(int));
    if (!arr2)
    {
        printf("Error in allocating heap memory.\n");
        return NULL;
    }

    for (i = 0; i < N; i++)
        *(arr2 + i) = 30 + rand() % 21;
    
    quicksort(arr, 0, N - 1);
    quicksort(arr2, 0, N - 1);

    merged = (int *) malloc ((2 * N) * sizeof(int));
    if (!merged)
    {
        printf("Error in allocating heap memory.\n");
        free(arr2);
        return NULL;
    }

    i = j = k = 0;

    while (i < N && j < N)
    {
        if (*(arr + i) <= *(arr2 + j))
        {
            *(merged + k) = *(arr + i);
            i++;
        }
        else
        {
            *(merged + k) = *(arr2 + j);
            j++;
        }
        k++;
    }  
    
    while (i < N)
    {
        *(merged + k) = *(arr + i);
        i++;
        k++;
    }

    while (j < N)
    {
        *(merged + k) = *(arr2 + j);
        j++;
        k++;
    }

    free(arr2);

    return merged;
}

void printArray(int *arr, int N)
{
    int i;

    printf("\n=========================================\n");
    printf("              ARRAY CONTENTS\n");
    printf("=========================================\n");

    for (i = 0; i < N; i++)
    {
        printf(" [%02d] -> %d\n", i, *(arr + i));
    }

    printf("=========================================\n");
}

void storeToFile(int *arr, int N)
{
    FILE *fp;
    int i;
    char filename[100];

    /* Create dynamic filename */
    snprintf(filename, sizeof(filename),
             "arr/array_N%d.txt", N);

    fp = fopen(filename, "w");
    if (!fp)
    {
        printf("!! Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "=========================================\n");
    fprintf(fp, "         ARRAY CONTENTS (N = %d)\n", N);
    fprintf(fp, "=========================================\n");

    for (i = 0; i < N; i++)
        fprintf(fp, "[%02d] -> %d\n", i, *(arr + i));

    fprintf(fp, "=========================================\n");

    fclose(fp);

    printf(">> Array successfully stored to '%s'\n", filename);
}

void showMenu(int *arr, int N)
{
    int choice;
    int pos, num, i;
    int *copy, *merged;

    do
    {
        printMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            return;
        }

        printf("\n-----------------------------------------\n");

        switch (choice)
        {
            case 1:
        
                printf("<< Serial Search >>\n");
                
                printf("Number to search: ");
                scanf("%d", &num);

                pos = serialSearch(arr, N, num);

                if (pos != -1)
                    printf("Found at position %d\n", pos);
                else
                    printf("Not found\n");

                break;
            
            case 2:
            
                printf("<< Quicksort >>\n");

                copy = (int*) malloc(N * sizeof(int));
                if (!copy)
                {
                    printf("Error in allocating heap memory.\n");
                    choice = -1;
                    break;
                }

                for (i = 0; i < N; i++)
                    copy[i] = arr[i];

                quicksort(copy, 0, N - 1);
                printArray(copy, N);

                free(copy);
                break;
            
            case 3:

                printf("<< Binary Search >>\n");

                copy = (int*) malloc(N * sizeof(int));
                if (!copy)
                {
                    printf("Error in allocating heap memory.\n");
                    choice = -1;
                    break;
                }

                for (i = 0; i < N; i++)
                    copy[i] = arr[i];

                quicksort(copy, 0, N - 1);

                printf("Number to search: ");
                scanf("%d", &num);

                pos = binarySearch(copy, 0, N - 1, num);

                if (pos != -1)
                    printf("Found in sorted array at index %d\n", pos);
                else
                    printf("Not found\n");

                free(copy);
                break;

            case 4:

                printf("<< Merge 2 sorted arrays >>\n");

                merged = mergeWithNewSortedArray(arr, N);
                if (!merged)
                {
                    choice = -1;
                    break;
                }

                printArray(merged, 2 * N);
                free(merged);
                break;

            case 5:
                printf("<< Print array at stdout >>\n");

                printArray(arr, N);
                break;

            case 6:
                printf("<< Store array at file >>\n");

                storeToFile(arr, N);
                break;

            case -1:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != -1);
}

void printMenu()
{
    printf("\n");
    printf("=========================================\n");
    printf("         ARRAY OPERATIONS MENU\n");
    printf("=========================================\n");
    printf("  1  ->  Serial Search\n");
    printf("  2  ->  Quicksort\n");
    printf("  3  ->  Binary Search\n");
    printf("  4  ->  Merge Sort\n");
    printf("  5  ->  Print Array\n");
    printf("  6  ->  Store Array to File\n");
    printf("-----------------------------------------\n");
    printf(" -1  ->  Exit Program\n");
    printf("=========================================\n");
}