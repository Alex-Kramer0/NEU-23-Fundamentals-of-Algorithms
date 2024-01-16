'''
Alex Kramer
Align Data Science
EECE 7205-16091
Project 1
'''

import sys
import timeit
import random

def __min_subarray_sum_dp(arr, j,i=0, groups=()):
    '''
    DYNAMIC PROGRAMMING APPROACH: 
    Function: Finds the minimum subarray sum by partitioning the input array into
    'j' non-empty subarrays.
    Args:
        arr (list): input array
        j (int): number of subarrays to partition the input array into
        i (int): current index (used for our recursion)
        groups (tuple): a tuple with the indices of elemetns in the group
    Returns: a tuple containering: a list of subarrays, the minimum subarray sum
    '''
    
    if len(groups) == j: 
        # if # of groups = j, return subarrays & min sum 
        # RT Notes: k= looping over the k groups // without dynamic it would be n or n*k
        G = [] 
        prev = 0 # prev index 
       
        for group_index in groups:
        # iterate through group index & calculate sub arrays
            if prev == 0:
                G.append(arr[group_index])
            else:
                G.append(arr[group_index] - arr[prev])
            prev = group_index
        return G, min(G) 
        # return subarrays & min sum 
    elif len(groups) < j and i == len(arr):
        # if # of groups < j return neg inf
        # meaning the partitioning is not possible 
        return [-float('inf')], -float('inf')

    else: # n+k -1 chose k-1
        # Recursion: look at both adding and not adding the current element to the group
        groups = tuple(groups)
        # Case 1: including the current element
        added = groups + (i,) 
        # case 2: excluding the current element 
        not_added = groups

        # Recursion: calculate the min subarrays for both cases
        max_added = __min_subarray_sum_dp(arr, j, i+1, added)
        max_not_added = __min_subarray_sum_dp(arr, j, i+1, not_added)
        
        # return
        return max(max_added, max_not_added, key=lambda x: x[1])
        


def __min_subarray_sum(arr, j,i=0, groups=()):
    '''
    Function: Finds the minimum subarray sum by partitioning the input array into
    'j' non-empty subarrays.
    Args:
        arr (list): input array
        j (int): number of subarrays to partition the input array into
        i (int): current index (used for our recursion)
        groups (tuple): a tuple with the indices of elemetns in the group
    Returns: a tuple containering: a list of subarrays, the minimum subarray sum
    '''

    if len(groups) == j:
        # if the # grous = j, calculate subarays
        groups += (len(arr),)
        G = []
        for group_index in range(len(groups)-1):
            # calculate subarrays by adding elements in each group
            G.append(sum(arr[groups[group_index]:groups[group_index+1]]))
        return G, min(G)
    elif len(groups) < j and i == len(arr):
        # if groups < j return -inf to show not possible
        return [-float('inf')], -float('inf')
    else:
        # recursion
        groups = tuple(groups)
        # case 1
        added = groups + (i,)
        # case 2
        not_added = groups
        # calculate for two cases 
        max_added = __min_subarray_sum(arr, j, i+1, added)
        max_not_added = __min_subarray_sum(arr, j, i+1, not_added)
        return max(max_added, max_not_added, key=lambda x: x[1])
        

def max_of_mins(arr, num_groups):
    '''
    Function: calculate the max of the min subarray 
    Args: 
        arr (list): input array
        num_groups (int): number of groups to partition 
    Reutnr: a tuple with the list of subarrays, and the max of the min subarray 
    '''
    # call the __min_subarray_sum with the input array & number of groups
    return __min_subarray_sum(arr, num_groups, i=0, groups=())

def max_of_mins_dp(arr, num_groups):
    '''
    Function: calculate the max of the min subarray for sums for the array,
                dyaminc programming approach
    Args: 
        arr (list): input array
        num_groups(int): number of groups to partition
    Return: a tuple with the list of subarrays and the max of the min subarray sums
    '''
    # calculate sums of input array to optimize subarray calculations
    arr_sums = [arr[0]]
    for i, each in enumerate(arr[1:]):
        arr_sums.append(arr_sums[i]+ each)
    return __min_subarray_sum_dp(arr_sums, num_groups, i=0, groups=())
    
def main(): 

    m = 3
    if len(sys.argv) > 1:
        arr = [ int(each) for each in sys.argv[1:]]
    else:
        arr = [3, 9, 7, 8, 2, 6, 5, 10, 1, 7, 6, 4]
    print('M = ', m)
    print("The input array is:", arr)
    print("The function returned:", max_of_mins_dp(arr, m))


    m = 4
    arr = [3, 9, 7, 8, 2, 6, 5, 10, 1, 7, 6, 4]
    print('M = ', m)
    print("The input array is:", arr)
    print("The function returned:", max_of_mins_dp(arr, m))
    
    m = 3
    arr = [12, 14, 3, 15, 9, 2, 11, 8, 12]
    print('M = ', m)
    print("The input array is:", arr)
    print("The function returned:", max_of_mins_dp(arr, m))
    
if __name__ == "__main__":
    main()