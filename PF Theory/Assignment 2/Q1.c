#include <stdio.h>
int main()
{
    int array[5], min1 = 9999, min2 = 9999; // Initialize value larger than input
    printf("Enter 5 elements for array (each < 9999):\n");
    for (int i = 0; i < 5; i++)
    {
        do
        {
            scanf("%d", &array[i]);
            if (array[i] >= 9999)
            {
                printf("Error! Value must be less than 9999\n");
            }
        } while (array[i] >= 9999);
    }
    for (int i = 0; i < 5; i++)
    {
        if (array[i] < min1)
        {
            min2 = min1;
            min1 = array[i];
        }
        // To ensure if values are not less than min1 but less than min2
        else if (array[i] < min2 && array[i] != min1)
        {
            min2 = array[i];
        }
    }
    // To ensure if all elements are same
    if (min2 == 9999)
    {
        printf("There is no second smallest element in the array.\n");
    }
    else
    {
        printf("Second smallest element in the array is: %d", min2);
    }
    return 0;
}