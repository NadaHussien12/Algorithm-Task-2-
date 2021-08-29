//Calling somw important libraries to help us in the program:
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

//Function(swap) to swap elements of data type(void) with parameters(a,b):
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


//Quick Sort Algorithm includes 2 functions(partition and quickSort) of different data types with parameters(array[] , low and high).
//Function to sort an array using (Quick Sort Algorithm).

//(1)Function (partition) of data type(integer) with parameters(array[] , low and high):
int partition(int array[], int first, int last)
{
  
// select the rightmost element as pivot
  int pivot = array[last];
  
// pointer for greater element
  int i = (first - 1);

// traverse each element of the array
// compare them with the pivot
  for (int j = first; j < last; j++)
   {
    if (array[j] <= pivot)
	{
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
   }

// swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[last]);
  
// return the partition point
  return (i + 1);
}

//(2)Function (quickSort) of data type(void) with parameters(array[] , low and high):
void quickSort(int array[], int first, int last) 
{
  if (first < last) 
  {
    
// find the pivot element such that elements smaller than pivot are on left of pivot elements greater than pivot are on right of pivot
    int pi = partition(array, first, last);
    
// recursive call on the left of pivot
    quickSort(array, first, pi - 1);
    
// recursive call on the right of pivot
    quickSort(array, pi + 1, last);
  }
}


//Insertion Sort Algorithm includes function(insertionSort) of data type(void) with parameters(arr[],n).
//Function to sort an array using (Insertion Sort Algorithm).

void insertionSort(int arr[], int n)
{
	
//Declaration of some variables	
	int i, key, j;
	for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position 
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


//Function (printArray) to print array elements of data type (void) and parameters(array[],size):
void printArray(int array[], int size) 
{
	
//Applying for loop:
  for (int i = 0; i < size; ++i) 
  {
  	
//printing the array after being sorted
    printf("%d ", array[i]);
  }
  printf("\n\n");
}

//Main Function:
int main()
 {
 	printf("The array of 1,000 random numbers is initialized.\n\n");
 	
 	//Declaration of some variables
   clock_t start,start1,end,end1;
 	
 	//Make a random array
   int randArray[1000],i;
   for(i=0;i<1000;i++)
   {
   
     randArray[i]=rand()%1000+1;
   }
  
	int n = sizeof(randArray) / sizeof(randArray[0]);
	  
	printf("Unsorted Array\n\n");
	printArray(randArray, n);
	  
	  

	printf("quick sort algorithm: \n\n");
	
	//Store time before function call 
	start1= clock();
	
	//Calling the function
    quickSort(randArray, 0, n - 1);
	printArray(randArray, n);
	
	//Store time after function call
	end1 = clock();
	  
		
	printf("insertion algorithm: \n\n");
	
	//Store time before function call 
	start = clock();
	
	//Calling the function
	insertionSort(randArray, n);
	printArray(randArray, n);
	
	//Store time after function call
	end = clock();
    
    //Calculate the time taken in seconds 
	double duration1 = ((double)end1 - start1)/CLOCKS_PER_SEC;
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	
	//Print the time on the console screen	
	printf("The array is sorted using quick sort in %f seconds\n", duration1);
	printf("The array is sorted using insertion sort in %f seconds\n", duration);

	return 0;
}



