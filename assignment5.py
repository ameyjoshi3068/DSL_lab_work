import math


class PercentageScores:
    def __init__(self):
        self.studList = []

    def set_scores(self):
        n = int(input("How many scores do you want to enter? "))
        for i in range(n):
            ele = float(input("Enter the percentages of student: "))
            self.studList.append(ele)
        return

    def insertion_sort(self):
        sorted_list = self.studList.copy()
        n = len(self.studList)
        for i in range(n):
            key = sorted_list[i]
            j = i
            while sorted_list[j - 1] > key and j >= 1:
                sorted_list[j] = sorted_list[j - 1]
                j -= 1
            sorted_list[j] = key
        return sorted_list

    def shell_sort(self):
        sorted_list = self.studList.copy()
        n = len(self.studList)
        gap = math.floor(n / 2)
        while gap > 0:
            i = 0
            j = gap
            while j < n:
                for a in range(i + gap, n, gap):
                    if sorted_list[a - gap] < sorted_list[a]:
                        sorted_list[a - gap], sorted_list[a] = sorted_list[a], sorted_list[a - gap]
                    else:
                        break
                i += 1
                j += 1
            gap = math.floor(gap / 2)

        return sorted_list


index = 9
ps_array = PercentageScores()
ps_array.set_scores()
while index != 0:
    print("To find Top 5 scorers in the data")
    print("Please select the sorting method by entering corresponding index and 0 to quit\n")
    print("1) Insertion sort")
    print("2) Shell Sort")

    index = input("Select an option: ")
    try:
        index = int(index)
    except ValueError:
        print("Invalid Selection \n\n")
        continue

    if index == 1:
        sorted_array = ps_array.insertion_sort()
        print("Top five scores are: ")
        for i in range(5):
            print(f"\t {i}) {sorted_array[-1]}")
            sorted_array.pop()
        print()
    elif index == 2:
        sorted_array = ps_array.shell_sort()
        print("Top five scores are: ")
        for i in range(5):
            print(f"\t {i}) {sorted_array[i]}")
        print()
    elif index == 0:
        break
    else:
        print("Invalid Selection \n\n")
