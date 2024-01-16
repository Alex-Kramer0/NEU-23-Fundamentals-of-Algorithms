"""
Alex Kramer
EECE 7250
Algorithms
Fall 2023
Homework 1
"""

import timeit
import copy

def insertion_sort(l):
    for i in range(1, len(l)):
        # starting at 1 rather than 0 
        j = i - 1
        # setting our j
        key = l[i]
        # key is the one we are inserting
        while (l[j] > key) and (j >= 0):
            # shift j to the right in the list, if j > 0 and j>k 
            l[j + 1] = l[j]
            j -= 1
        l[j + 1] = key
        
       
        # insertion spot 
    return l

def merge(A, start, mid, end):
    
    end_1 = mid - start
    end_2 = end - mid

    if A[mid - 1] <= A[mid]:
        return
    
    L,R = A[:mid], A[mid:]
    # setting the sub arrays

    L_count = R_count = 0
    count = start
    # setting varaibles all = 0

    while L_count< end_1 and R_count < end_2:
        # swapping 
        if (L[L_count]< R[R_count]):
            A[count] = L[L_count]
            L_count += 1
        else:
            A[count] = R[R_count]
            R_count += 1
        count += 1
    
    while L_count < end_1:
        A[count] = L[L_count]
        L_count += 1
        count += 1
    while R_count < end_2:
        A[count] = R[R_count]
        count =+ 1
        R_count =+1

def q_merge_sort(A, start, end):
    if start >= end -1:
        return
    mid = (start + end) // 2
    q_merge_sort(A, start, mid)
    q_merge_sort(A, mid, end)
    merge(A, start, mid, end)

def merge_sort(A):
    q_merge_sort(A, 0, len(A))


if __name__ == '__main__':
    print(globals())
    # acting as main function
    insertion = 'insertion_sort(B)'
    merge_ = 'merge_sort(B)'
    A = []
    for i in range(1000):
        A = [i] + A 
        B = copy.deepcopy(A)
        
        merge_time = timeit.timeit(merge_, globals=globals(), number=100)
        B = copy.deepcopy(A)
        insertion_time = timeit.timeit(insertion, globals=globals(), number=100)
        if merge_time - insertion_time < 0:
            print(i, merge_time, insertion_time, merge_time - insertion_time)