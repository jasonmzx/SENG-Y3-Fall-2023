#include<iostream>
//!Time Complexity: O(N2)		|		LAB 5 SYSTEMS PROGRAMMING

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) { //! NOTE: at the end of every I loop iteration, we know that the Array[Length-1] Element is the MAX ELEMENT in array
		
		swapped = false;

		//End at (n-i) - 1, so that the last J+1 iteration doesn't refer an out of bound element
		for (j = 0; j < n - i - 1; j++) {

			// swap if number at index. J is larger than number at index J+1 
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]); //std::swap Swaps 2 values between different variables, or indices in an array
				swapped = true;
			}
		}

		// If no two elements were swapped
		// by inner loop, then break, this is to ensure an "Early" Breakout point if possible, slightly optimizing the algo
		if (swapped == false)
			break;
	}
}

int main() {
	int arrLen;
	std::cout << "Enter the length of your array: ";
	std::cin >> arrLen;

	// Allocate memory for the array
	int* arrBubble = new int[arrLen];

	std::cout << "Please enter " << arrLen << " integer values for the array:\n";
	for (int x = 0; x < arrLen; x++) {
		std::cin >> arrBubble[x];
	}

	bubbleSort(arrBubble, arrLen);

	std::cout << "Sorted array: \n";
	for (int i = 0; i < arrLen; i++) {
		std::cout << arrBubble[i] << " ";
	}
	std::cout << std::endl;

	// Free the allocated memory, Note: C++ doesn't have access to system commands like free() and malloc! I guess it has a garbage collector?
	delete[] arrBubble;

	return 0;
}
