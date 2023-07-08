# CPP-Treasure Trove
A collection of standalone useful (or not!) scripts written in cpp, as the byproducts of my personal cpp journey. As of the writing, the only dependency is the boost library.

## Build Requirements
1. libboost-all-dev 1.71

## Contents
1. merge_list - Merge 2 input arrays into a single array.

2. binary_gap

3. cakecutter

4. largestpeak

5. palindrome

### 1. merge_list
```
>> g++ -o merge_list merge_list.cpp cmdutils.cpp -lboost_program_options
>> ./merge_list --list 1 2 3 4 --list 1 1 2 3
>>
1 2 3 4
1 1 2 3
1 1 1 2 2 3 3 4
```
