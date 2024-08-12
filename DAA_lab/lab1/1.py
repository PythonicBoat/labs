import time
import random

def find_second_smallest_largest(arr):
    smallest = float('inf')
    largest = float('-inf')
    second_smallest = float('inf')
    second_largest = float('-inf')

    for num in arr:
        if num < smallest:
            second_smallest = smallest
            smallest = num
        elif num < second_smallest and num != smallest:
            second_smallest = num

        if num > largest:
            second_largest = largest
            largest = num
        elif num > second_largest and num != largest:
            second_largest = num

    return second_smallest, second_largest

def main():
    n = int(input("Enter the maximum power of 10 for array size: "))

    for power in range(1, n + 1):
        size = 10 ** power
        arr = [random.randint(0, 99) for _ in range(size)]

        start_time = time.time()
        
        second_smallest, second_largest = find_second_smallest_largest(arr)
        
        elapsed_time = time.time() - start_time

        print(f"Array size: {size}")
        print(f"Second smallest: {second_smallest}")
        print(f"Second largest: {second_largest}")
        print(f"Elapsed time: {elapsed_time:.6f} seconds\n")

if __name__ == "_main_":
    main()