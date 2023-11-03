from math import floor


class SearchingAlgorithms:
    def __init__(self) -> None:
        self.array = []
        self.sorted_array = []

    def set_array(self):
        for i in range(int(input("How many elements do you want to enter? -> "))):
            self.array.append(int(input("Enter the Roll Number: ")))
        self.sorted_array = self.array.copy()
        self.sorted_array.sort()

    def linear_search(self):
        k = int(input("Enter the number you want to search: "))
        for i in self.array:
            if i == k:
                return i
        return -1

    def sentinel_search(self):
        k = int(input("Enter the number you want to search: "))
        n = len(self.array)
        last = self.array[n - 1]
        self.array[n - 1] = k
        i = 0
        while self.array[i] != k:
            i += 1
        if last == self.array[n - 1]:
            return n - 1
        elif i != n - 1:
            self.array[n - 1] = last
            return i
        else:
            self.array[n - 1] = last
            return -1

    def binary_search(self):
        k = int(input("Enter the number you want to search: "))
        begin = 0
        end = len(self.array) - 1

        while begin <= end:
            mid = floor((begin + end) / 2)
            if self.sorted_array[mid] == k:
                return True
            elif k > self.sorted_array[mid]:
                begin = mid + 1
            else:
                end = mid - 1
        else:
            return False

    def fibonacci_search(self):
        x = int(input("Enter the number you want to search: "))
        n = len(self.sorted_array)
        fn2 = 0
        fn1 = 1
        fn = fn1 + fn2
        while fn < n:
            fn2 = fn1
            fn1 = fn
            fn = fn1 + fn2

        offset = -1
        while fn > 1:
            i = min(offset + fn2, n - 1)
            if x == self.sorted_array[fn2]:
                return i
            elif x < self.sorted_array[fn2]:
                fn = fn2
                fn1 = fn1 - fn2
                fn2 = fn - fn1
            else:
                offset = i
                fn = fn1
                fn1 = fn2
                fn2 = fn - fn1
                offset = i

        if fn1 and self.sorted_array[n - 1] == x:
            return n - 1
        return -1


index = 9
algo = SearchingAlgorithms()
algo.set_array()
while index != 0:
    print("Please select the searching method by entering corresponding index and 0 to quit\n")
    print("1) Linear search")
    print("2) Sentinel search")
    print("3) Binary search ")
    print("4) Fibonacci search\n")

    index = input("Select an option: ")
    try:
        index = int(index)
    except ValueError:
        print("Invalid Selection \n\n")
        continue

    if index == 1:
        if algo.linear_search() == -1:
            print("student didn't attend training program")
        else:
            print("student attended training program")
        print()
    elif index == 2:
        if algo.sentinel_search() == -1:
            print("student didn't attend training program")
        else:
            print("student attended training program")
        print()
    elif index == 3:
        if not algo.binary_search():
            print("student didn't attend training program")
        else:
            print("student attended training program")
        print()
    elif index == 4:
        if not algo.binary_search():
            print("student didn't attend training program")
        else:
            print("student attended training program")
        print()
    elif index == 0:
        break
    else:
        print("Invalid Selection \n\n")
