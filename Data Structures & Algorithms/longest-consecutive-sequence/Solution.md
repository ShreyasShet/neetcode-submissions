
# Longest Common Sequence

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in `O(n)` time.

# First Principles Thinking

Brute Force -> Discover Redundancy -> Introduce an invariant -> Augment the invariant -> Discover new paradigm

## Brute Force

Sort the array, `T(n) = O(n logn)` where `n` is number of elements in the array.\
Scan the array, `T(n) = O(n)`
Total = `O(n logn)`

## Discovering Redundancy

The above brute force is quite optimized but we only care if `x` is present then check for `x + 1` so that we extend the sequence.
Hence say if `1` is present, we look for `2`, we look for `3` and so on until the sequence starting from the element cannot be continued.
Thus sorting only helps us with relative ordering and is redundant when duplicates are present. Hence say if we encounter `1` then,
we scan the entire array to look for and again to look for `3`. Thus by introducing this invariant we might have removed sorting but
we accidentally discovered an unoptimized solution with `T(n) = O(n^2)`

## Introduce Invariant

Thus to form a sequence it is best to only consider distinct input which can support a better optimized lookup unlike the `O(n^2)`
scan. Thus to introduce an invariant that considers only distinct inputs we can make use of a Hash set.\
eg: nums = {1, 2, 2, 3, 4, 20, 10, 100}
 
S = {1, 2, 3, 4, 20, 10, 100},

now say we encounter `1` and we have to look for `2` we can easily find out using Hash set which supports `O(1)` lookup and solves the
problem associated with the duplicates

## Extend Invariant to the solution 

Hence as we traverse the elements in the set, say we encounter `x` then we can lookup for `x+1` and continue the sequence. The stopping 
condition for this problem will be when you cannot find `x+1` and you stop counting the sequence length as this new element can mark the 
beginning of the new sequence. Also say you encounter `x` and `x-1 ∈ S` then you can skip the element because its predecessor is present
and hence `x` cannot be the start of another sequence.
