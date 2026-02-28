#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    arr = (int *) malloc(N * sizeof(int));
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

void showMenu(int *arr, int N)
{
    int choice;

    do
    {
        printMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n-----------------------------------------\n");

        switch (choice)
        {
        case 1:
            printf(">> Serial Search selected\n");
            break;

        case 2:
            printf(">> Sorting array...\n");
            break;

        case 3:
            printf(">> Binary Search selected\n");
            break;

        case 4:
            printf(">> Performing Merge Sort...\n");
            break;

        case 5:
            printf(">> Printing array...\n");
            break;

        case 6:
            printf(">> Storing array to file...\n");
            break;

        case -1:
            printf(">> Exiting program. Goodbye!\n");
            break;

        default:
            printf("!! Invalid choice. Please try again.\n");
            break;
        }

    } while (choice != -1);
}

void printMenu()
{
    printf("\n");
    printf("=========================================\n");
    printf("         ARRAY OPERATIONS MENU\n");
    printf("=========================================\n");
    printf("  1  ➤  Serial Search\n");
    printf("  2  ➤  Sort (Ascending)\n");
    printf("  3  ➤  Binary Search\n");
    printf("  4  ➤  Merge Sort\n");
    printf("  5  ➤  Print Array\n");
    printf("  6  ➤  Store Array to File\n");
    printf("-----------------------------------------\n");
    printf(" -1  ➤  Exit Program\n");
    printf("=========================================\n");
}