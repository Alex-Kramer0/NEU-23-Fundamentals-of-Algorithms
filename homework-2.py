"""
Alex Kramer
EECE 7250
Algorithms
Fall 2023
Homework 2
"""

# Imports
import random
import time
'''
    QUICK SORT
'''
def partition(array, start, end):
    '''
    '''

    pivot = array[start]
    count = 0 # number of elements less than or equal to the pivot
    for each in array[start+1:end+1]:
        if each <= pivot:
            count += 1

    # Giving pivot element its correct position 
    pivot_i = start + count # start at the correct index for pivot
    temp = array[pivot_i]
    array[pivot_i] = array[start]
    array[start] = temp

    # Sorting left and right parts of the pivot elemetns
    i, j = start, end

    while (i < pivot_i and j > pivot_i):
        while (array[i] <= pivot):
            # find out of order elements < left side > 
            i += 1
        while (array[j] > pivot):
            # find out of order elements < right side >
            j -= 1
        if (i < pivot_i and j > pivot_i):
            # Swap them if they are out of order
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
            i += 1
            j -= 1

    return pivot_i

def quickSort(array, start, end):
    '''
    Recursion 
    '''

    if (start >= end):
        return
    # get pivot
    p = partition(array, start, end)
    # < Left Side >
    quickSort(array, start, p - 1)
    # < Right Side >
    quickSort(array, p + 1, end)

def QuickSort(arr):
    start_time = time.time()
    quickSort(arr,0,len(arr)-1)
    end_time = time.time()
    elapsed_time_quick_sort = end_time - start_time
    print('\nQuick Sort Time: ', elapsed_time_quick_sort)



'''
    QUICK SORT - From Textbook
'''
def _partition(array, start, end):
    pivot = array[end]
    pivot_i = start - 1 # number of elements less than or equal to the pivot
    for j in range(start, end):
        if array[j] <= pivot:
            pivot_i += 1
            array[pivot_i], array[j] = array[j], array[pivot_i]
    array[pivot_i+1], array[end] = array[end], array[pivot_i+1]

    return pivot_i + 1

def quick_Sort(array, start, end):
    '''
    Recursion 
    '''
    if (start >= end):
        return
    # get pivot
    p = _partition(array, start, end)
    # < Left Side >
    quick_Sort(array, start, p - 1)
    # < Right Side >
    quick_Sort(array, p + 1, end)

def Quick_Sort(arr):
    quick_Sort(arr,0,len(arr)-1)


'''
    RANDOMIZED QUICK SORT
'''
def R_pivot(array, start, end):
    '''

    '''
    # Get random index for pivot
    p = random.randrange(start, end)
    array[start], array[p] = array[p], array[start]
    return _partition(array, start, end)
    
def rand_quick_Sort(array, start, end):
    '''
    Recursion 
    '''
    if (start >= end):
        return
    # get pivot
    p = R_pivot(array, start, end)
    # < Left Side >
    rand_quick_Sort(array, start, p - 1)
    # < Right Side >
    rand_quick_Sort(array, p + 1, end)

def Rand_quick_Sort(array):
    start_time = time.time()
    rand_quick_Sort(array, 0, len(array)-1)
    end_time = time.time()
    elapsed_time_quick_sort = end_time - start_time
    print('\nRandomized Quick Sort Time: ', elapsed_time_quick_sort)
    
'''
    HEAP SORT
'''
def heapify(array, n, i):
    # max heapify 
    max = i
    l = 2 * i + 1
    r = 2 * i + 2

    # l > root
    if (l < n and array[l] > array[max]):
        max = l
    # r > root
    if (r < n and array[r] > array[max]):
        max = r

    if (max != i):
        # swap if two moves
        temp = array[i]
        array[i] = array[max]
        array[max] = temp
        # recursively calls heapify to sort affected sub-trees
        heapify(array, n, max)

def build_heap(array, size):
    # calls heapify on each level (which sorts every element)

    i = size
    for i in range(size, -1, -1):
        heapify(array, size, i)

def pop_max(array, size):
    # returns max element
    ans = array[0]
    array[0] = array[size - 1]
    heapify(array, size, 0)
    return ans

def heap_sort(array, size):
    build_heap(array, size)
    call_count = 0
    from_end = size - 1
    while (call_count < size):
        array[from_end - call_count] = pop_max(array, (from_end - call_count + 1))
        call_count += 1

def Heap_Sort(array):
    heap_sort(array, len(array))


'''
    COUNTING SORT
'''
def counting_sort(A,k):

    B = [0] * len(A)
    C = [0] * (k+1)
    

    for j in range(len(A)):
        C[A[j]] += 1
        # C[i] = number of elements equal to i 
    
    for i in range(1,k):
        C[i] += C[i-1]
        # C[i] = number of elements less than or equal to i

    for j in range(len(A)-1, 0, -1):
        B[C[A[j]]] = A[j]
        C[A[j]] = C[A[j]] - 1
        
    return B[1:]

'''
    RADIX SORT
'''
def Radix_Sort(A, k):
    n = len(A)
    output = [0] * (n) 
    count = [0] * (10) 
   
    for i in range(n): 
        count[int((( A[i] / k)) % 10)] += 1
   
    for i in range(1, 10): 
        count[i] += count[i-1] 
   
    i = n-1
    while i>=0:
        output[count[int(((A[i]/k))%10) ] - 1] = A[i] 
        count[int(((A[i]/k))%10)] -= 1
        i -= 1

    i = 0
    for i in range(0,len(A)): 
        A[i] = output[i] 

def radixSort(A):
    m = max(A)
    k = 1
    while m // k > 0:
        Radix_Sort(A, k)
        k *= 10

'''
    HELPER FUNCTIONS
'''
def print_array(A):
    for i in A:
        print(i)

def generate_rand_array():
    array = []
    for i in range(0, 100):
        n = random.randint(1,100)
        array.append(n) 
    return array

def generate_uniq_array():
    arr = generate_array()
    random.shuffle(arr)
    return arr

def generate_array():
    array = []
    for i in range(0, 100):
        array.append(i) 
    return array

'''
    TESTING
'''
def main():
    '''
    UA = generate_uniq_array()
    RA = generate_rand_array()
    same = [1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 0]
    arr = RA
    Sort = Heap_Sort
    Sort(arr)
    if arr == sorted(arr):
        print('sort works')
    else:
        print('sort not works')
    

    print('\n\nTESTING QUICK SORT: \n')
    UA = generate_uniq_array()
    print('Unsorted Unique Array: ', UA)
    Quick_Sort(UA)
    print('\nSorted: ', UA)
    RA = generate_rand_array()
    print('\nUnsorted Random Array: ', RA)
    Quick_Sort(RA)
    print('\nSorted: ', RA)

    print('\n\nTESTING RANDOMIZED QUICK SORT: \n\n')
    UA = generate_uniq_array()
    print('Unsorted Unique Array: ', UA)
    Rand_quick_Sort(UA)
    print('\nSorted: ', UA)
    RA = generate_rand_array()
    print('\nUnsorted Random Array: ', RA)
    Rand_quick_Sort(RA)
    print('\nSorted: ', RA)

    print('\n\nTESTING HEAP SORT: \n')
    UA = generate_uniq_array()
    print('Unsorted Unique Array: ', UA)
    Heap_Sort(UA)
    print('\nSorted: ', UA)
    RA = generate_rand_array()
    print('\nUnsorted Random Array: ', RA)
    Heap_Sort(RA)
    print('\nSorted: ', RA)

    print('\n\nTESTING COUNTING SORT: \n')
    arr = [20, 18, 5, 7, 16, 10, 9, 3, 12, 14, 0]
    print('Unsorted Array:', arr)
    B = counting_sort(arr, 20)
    print('\nSorted:', B)

    print('\n\nTESTING RADIX SORT: \n')
    A = [329, 457, 657, 839, 436, 720, 353]
    print('Unsorted Array:', arr)
    a = radixSort(arr)
    print('\nSorted:', A, '\n')
    
    ar = generate_rand_array()
    arr = generate_rand_array()

    for i in range(5):
        QuickSort(ar)
        Rand_quick_Sort(arr)
    '''
if __name__ == "__main__":
    main() 