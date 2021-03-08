// C++ program for visualization of bubble sort 

#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std; 

// Global Variables 
vector<int> numbers;
int sortingAlgoSelection = -1;
int arraySize = -1;
int sortSpeed = -1;
int leftPtr = 0;
int rightPtr = -1;
int smallest = INT_MIN;
bool isSorted = false;

// Bubble sort function 
void bubbleSortOneTime();

// Insertion Sort function 
void insertionSortOneTime();

// Selection Sort function 
void selectionSortOneTime();

// Quick Sort function --- Recursive
void quickSortOneTime(vector<int> &array, int startIdx, int endIdx);

// Draw
void Draw();

// Setup
void Setup();

// 
void printSortingOptions();

// Driver program 
int main() 
{
    Setup();

    switch (sortingAlgoSelection)
    {
    case 1:
        while(!isSorted){
            Draw();
            bubbleSortOneTime();
            Sleep(1000 / (sortSpeed * sortSpeed));
        }
        break;
    case 2:
        for (leftPtr = 1; leftPtr < arraySize + 1; leftPtr++){
            Draw();
            isSorted = true;
            insertionSortOneTime();
            Sleep(1000 / (sortSpeed * sortSpeed));
        }
        break;
    case 3:
        do{
            Draw();
            selectionSortOneTime();
            Sleep(1000 / (sortSpeed * sortSpeed));
        }while (leftPtr < arraySize);
        break;
    case 4:
        Draw();
        quickSortOneTime(numbers, 0, numbers.size() - 1);
        break;
    default:
        cout << "Oops... Something is wrong!";
        break;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Array is sorted \n";
    
    getch();
    return 0; 
}

// Setting up the main numbers array with user's parameters
void Setup()
{
    while(!(arraySize > 0)){
        cout << "Size of the array that will be sorted => ";
        cin >> arraySize;
        if (arraySize < 1)
            cout << "Please enter an array size of at least 1.\n";
    }
    while(!(sortSpeed > 0 && sortSpeed < 11)){
        cout << "Sorting Speed (Between 1(slowest) - 10(fastest)) => ";
        cin >> sortSpeed;
        if (sortSpeed < 1 || sortSpeed > 10)
            cout << "Please enter a sorting speed between 1 - 10.\n";
    }
    
    printSortingOptions();
    while (!(sortingAlgoSelection > 0 && sortingAlgoSelection < 5)){
        cin >> sortingAlgoSelection;
        if (sortingAlgoSelection < 0 || sortingAlgoSelection > 4)
            cout << "Please select an option between 1 - 4.\n";
    }

    leftPtr = 0;
    rightPtr = (arraySize > 1) ? leftPtr + 1 : 0;

    srand(time(NULL));

    for(int i=0; i < arraySize; i++){
        numbers.push_back(rand() % 100 + 1);
    }
}

void printSortingOptions(){
    cout << "\nSorting Algorithm Options\n";
    cout << "\t1 - Bubble Sorting \n";
    cout << "\t2 - Insertion Sorting \n";
    cout << "\t3 - Selection Sorting \n";
    cout << "\t4 - Quick Sorting \n";
    cout << "\n\tPlease choose a sorting algorithm from above options: ";
}

// Draw Function
void Draw()
{
    system("cls");
    switch (sortingAlgoSelection)
    {
    case 1:
        cout << "Bubble Sort sorting algorithm." << "\n";
        break;
    case 2:
        cout << "Insertion Sort sorting algorithm." << "\n";
        break;
    case 3:
        cout << "Selection Sort sorting algorithm." << "\n";
        break;
    case 4:
        cout << "Quick Sort sorting algorithm." << "\n";
        break;
    default:
        cout << "Oops... Something is wrong!";
        break;
    }
    cout << "-------------------------------------------------------\n";
    for(int numberIdx = 0; numberIdx < arraySize; numberIdx++){
        cout << numbers[numberIdx] << "\t";
        for(int i = 0; i < numbers[numberIdx]; i++){
            cout << "o";
        }
        if (numberIdx == leftPtr || numberIdx == rightPtr){
            cout << " <-";
        }
        cout << "\n";
    }
}

// Bubble Sort for One Time
void bubbleSortOneTime()
{
    isSorted = true;
    for (leftPtr = 0; leftPtr < arraySize - 1; leftPtr++){
        rightPtr = (arraySize > 1) ? leftPtr + 1 : 0;
        if (numbers[leftPtr] > numbers[rightPtr]){
            swap(numbers[leftPtr], numbers[rightPtr]);
            isSorted = false;
        }  
    } 
}

// Insertion Sort for One Time
void insertionSortOneTime()
{
    rightPtr = leftPtr;
    while(rightPtr > 0 && numbers[rightPtr] < numbers[rightPtr - 1]){
        swap(numbers[rightPtr], numbers[rightPtr - 1]);
        isSorted = false;
        rightPtr--;
    }
}

// Selection Sort for One Time
void selectionSortOneTime()
{
    isSorted = true;
    smallest = numbers[leftPtr];
    for(int i = leftPtr; i < arraySize; i++){
        if(numbers[i] < smallest){
            smallest = numbers[i];
            rightPtr = i;
            isSorted = false;
        }
    }
    if(!isSorted){
        swap(numbers[leftPtr], numbers[rightPtr]);
    }
    leftPtr++;
}

// Quick Sort for One Time
void quickSortOneTime(vector<int> &array, int startIdx, int endIdx)
{
    if(startIdx >= endIdx){
		return;
	}

    int pivotIdx = startIdx;
	int leftIdx = startIdx + 1;
	int rightIdx = endIdx;
    leftPtr = leftIdx;
    rightPtr = rightIdx;
    Draw();
	Sleep(1000 / (sortSpeed * sortSpeed));
	while(rightIdx >= leftIdx){
		if (array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]){
			swap(array[leftIdx], array[rightIdx]);
            leftPtr = leftIdx;
            rightPtr = rightIdx;
            Draw();
            Sleep(1000 / (sortSpeed * sortSpeed));
		}
		if(array[leftIdx] <= array[pivotIdx]){
			leftIdx++;
		}
		if(array[rightIdx] >= array[pivotIdx]){
			rightIdx--;
		}
	}
    swap(array[rightIdx], array[pivotIdx]);
    leftPtr = leftIdx;
    rightPtr = rightIdx;
    Draw();
    Sleep(1000 / (sortSpeed * sortSpeed));
	bool isLeftSubarraySmaller = rightIdx - 1 - startIdx < endIdx - rightIdx + 1;
	if(isLeftSubarraySmaller){
		quickSortOneTime(array, startIdx, rightIdx - 1);
		quickSortOneTime(array, rightIdx + 1, endIdx);
	}
	else {
		quickSortOneTime(array, rightIdx + 1, endIdx);
		quickSortOneTime(array, startIdx, rightIdx - 1);
	}
}

// END 