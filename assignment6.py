class PercentageScores:
    def __init__(self):
        self.studList = []

    def set_scores(self):
        n = int(input("How many scores do you want to enter? "))
        for i in range(n):
            ele = float(input("Enter the percentages of student: "))
            self.studList.append(ele)
        return

    def quick_sort(self):
        def partition(array, low, high):

            pivot = array[high]

            i = low - 1

            for j in range(low, high):
                if array[j] <= pivot:
                    i = i + 1

                    (array[i], array[j]) = (array[j], array[i])

            (array[i + 1], array[high]) = (array[high], array[i + 1])

            return i + 1
        def quickSort(array, low, high):
            if low < high:
                pi = partition(array, low, high)
                quickSort(array, low, pi - 1)
                quickSort(array, pi + 1, high)

        quickSort(self.studList,0,len(self.studList)-1)

        return self.studList

    @staticmethod
    def print_top_five(list1):
        print("Top five scores are: ")
        for i in range(5):
            print(f"\t {i}) {list1[-1]}")
            list1.pop()


index = 9
ps_array = PercentageScores()
ps_array.set_scores()
print("\n")
print("Finding Top 5 scores in the dat using quick sort")

print()
sorted_array = ps_array.quick_sort()
ps_array.print_top_five(sorted_array)
