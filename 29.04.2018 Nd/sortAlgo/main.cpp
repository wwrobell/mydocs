#include <iostream>
#include <list>

void swap(int * p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void printArray(int* begin, int* end) {
	while (begin != end) {
		std::cout << *begin << ",";
		++begin;
	}
	std::cout << "\n";
}

std::list<int> insertionSort(int* begin, int* end) {
	std::list<int>sorted;
	sorted.push_back(*begin);
	++begin;

	while (begin != end) {
		bool added = false;
		for (std::list<int>::iterator it = sorted.begin(); it != sorted.end(); ++it) {
			if ((*begin) <= *it) {
				sorted.insert(it, *begin);
				added = true;
				break;
			}
		}
		if (!added)
			sorted.push_back(*begin);

		++begin;
	}
	return sorted;
}

void selectionSort(int* begin, int* end) {
	int* min;

	while (begin != end) {
		int* it = begin;
		min = begin;
		//find minimum
		while (it != end) {
			if ((*it) < (*min))
				min = it;
			++it;
		}

		//swap begin z min
		int begin_copy = *begin;
		*begin = *min;
		*min = begin_copy;
		++begin;
	}
}

void selectionSortRec(int* begin, int* end) {
	int* it = begin;
	int* min = begin;
	while (it != end) {
		if ((*it) < (*min))
			min = it;
		++it;
	}

	swap(begin, min);
	++begin;
	if (begin!=end)
		selectionSortRec(begin, end);
}

void bubbleSort(int* begin, int* end) {
	int swapCount(0);
	do{
		int* it = begin;
		swapCount = 0;
		while (it != (end-1)) {
			if ((*it) > *(it + 1)) {
				//swap elements
				int copyInt = *it;
				*it = *(it + 1);
				*(it + 1) = copyInt;
				++swapCount;
			}
			++it;
		}
	} while (swapCount != 0);
}

void printList(std::list<int> lista) {
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		std::cout << *it << ",";
	}
	std::cout << "\n";
}

int* partitionArr(int* begin, int* end) {
	// porzadkuje tablice; na lewo od pivota - elementy od niego mniejsze; na prawo - wieksze
	// zwraca wskaznik na pivot

	int* pivot = end - 1;
	int* i = begin - 1;
	int* j = begin;
	
	while (j != pivot) {
		if (*j > *pivot)
			++j;
		else {
			++i;
			swap(i, j);
			++j;
		}
	}
	swap((i + 1), pivot);
	///////////////////////
	return (i + 1);
}

void quickSort(int* begin, int* end) {
	if (begin != end) {
		int* pivotPtr = partitionArr(begin, end);
		quickSort(begin, pivotPtr);
		quickSort((pivotPtr + 1), end);
	}
}

void countingSort() {
	const int n = 15;
	const int k = 10;//zakres kluczy 0-9

	int arr[n] = { 3,3,1,2,4,5,6,4,7,8,1,2,4,0,6 };
	int arrSorted[n];
	int histogram[k];
	for (int i = 0; i < k; ++i) {
		histogram[i] = 0;
	}

	//zliczanie wystapien elementow
	for (int i = 0; i < n; ++i) {
		histogram[arr[i]] += 1;
	}

	int tresh(0);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < histogram[i]; ++j) {
			arrSorted[tresh] = i;
			++tresh;
		}
	}
	std::cout << "asd";
}

int main() {
	//int size(7);
	int arr[] = {18,22, 12,10,4,2,6,7,3, 1, 81, 19, 11, 5};
	//std::list<int> posortowana = insertionSort(arr, std::end(arr));
	//printArray(arr, std::end(arr));
	//printList(posortowana);

	//selectionSort(arr, std::end(arr));
	//bubbleSort(arr, std::end(arr));
	//printArray(arr, std::end(arr));
	//std::list<int> l = { 7, 5, 16, 8 };
	//std::list<int> lSorted = quickSort(l);
	//printList(lSorted);
	//quickSort(arr, std::end(arr));
	selectionSortRec(arr, std::end(arr));
	printArray(arr, std::end(arr));

	//countingSort();
	return 0;
}