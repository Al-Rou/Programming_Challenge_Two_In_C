#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Enter numbers: ");
    char inputNumbers[100];
    //Receiving numbers
    scanf("%s", &inputNumbers);
    char arraySize[3];
    int i = 0;
    //Finding the size of needed array
    while(inputNumbers[i] != ';')
    {
        arraySize[i] = inputNumbers[i];
        i++;
    }
    int sizeInInt = atoi(arraySize);
    int inputArray[sizeInInt];
    //Storing input numbers into the defined array
    char auxiliary[100];
    int counterOfauxiliary = 0;
    char auxTwo[100];
    int counterOfArray = 0;
    for(int j = i+1; j < strlen(inputNumbers); j++)
    {
        if(inputNumbers[j] != ',')
        {
            auxiliary[counterOfauxiliary] = inputNumbers[j];
            counterOfauxiliary++;
        }
        else
        {
            inputArray[counterOfArray] = atoi(auxiliary);
            counterOfArray++;
            strcpy(auxiliary, auxTwo);
            counterOfauxiliary = 0;
        }
    }
    inputArray[counterOfArray] = atoi(auxiliary);
    //Sorting the array
    for(int k = 0; k < sizeInInt-1; k++)
    {
        for(int z = k+1; z < sizeInInt; z++)
        {
            if(inputArray[k] > inputArray[z])
            {
                int tempVar = inputArray[k];
                inputArray[k] = inputArray[z];
                inputArray[z] = tempVar;
            }
        }
    }
    //Finding two neighbors which are equal to each other
    for (int z = 0; z < sizeInInt-1; z++)
    {
        if(inputArray[z] == inputArray[z+1])
        {
            printf("%d", inputArray[z]);
        }
    }

    fflush(stdout);
    return 0;
}
