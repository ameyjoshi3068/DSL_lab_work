class Matrix:
    def __init__(self, matrix=[]):
        self.i = 0
        self.j = 0
        self.matrix = []

        if matrix:
            self.i = len(matrix)
            self.j = len(matrix[0])
            self.matrix = matrix

    def set_matrix(self, i, j):
        self.i = i
        self.j = j
        for x in range(i):
            tmp = []
            y = 0
            while y < j:
                try:
                    ele = int(input(f"Enter the element in row {x + 1} column {y + 1} : "))
                    y += 1
                except ValueError:
                    print("Invalid element")
                    continue
                tmp.append(ele)

            self.matrix.append(tmp)

    def __str__(self) -> str:
        out = ""
        for ind in range(self.i):
            out = out + str(self.matrix[ind]) + "\n"
        return out

    def find_saddle_point(self):
        small = []
        large = []

        for ind in range(self.i):
            smallest = self.matrix[ind][0]
            for ind2 in range(self.j):
                if self.matrix[ind][ind2] < smallest:
                    smallest = self.matrix[ind][ind2]
            small.append(smallest)

        for ind in range(self.j):
            largest = self.matrix[ind][0]
            for ind2 in range(self.i):
                if self.matrix[ind2][ind] > largest:
                    largest = self.matrix[ind2][ind]
            large.append(largest)

        for ind1 in range(self.i):
            for ind2 in range(self.j):
                if small[ind1] == large[ind2]:
                    return ind1, ind2
        return -1, -1


while True:
    try:
        i = int(input("Enter the number of rows in A: "))
        j = int(input("Enter the number of columns in A: "))
        break
    except ValueError:
        print("Invalid Number \n\n")
print("Enter the elements for matrix A")

a = Matrix()
a.set_matrix(i, j)
print()

i, j = a.find_saddle_point()

if i == -1:
    print("There is no saddle point in matrix")
else:
    print(f"There is a saddle pint in matrix at position ({i+1}, {j+1})")
