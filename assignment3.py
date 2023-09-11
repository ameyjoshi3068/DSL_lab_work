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

    def transpose(self):
        tmp = []
        for b in range(self.j):
            tmp2 = []
            for a in range(self.i):
                tmp2.append(self.matrix[a][b])
            tmp.append(tmp2)

        return Matrix(matrix=tmp)

    def __str__(self) -> str:
        out = ""
        for a in range(self.i):
            out = out + str(self.matrix[a]) + "\n"
        return out

    def __add__(self, other):
        if self.i == other.i and self.j == other.j:
            ans = []
            for a in range(self.i):
                tmp = []
                for b in range(self.j):
                    tmp.append(self.matrix[a][b] + other.matrix[a][b])
                ans.append(tmp)

            m = Matrix(matrix=ans)
            return m
        else:
            print("Matrices having different number of rows and columns cannot be added")

    def __sub__(self, other):
        if self.i == other.i and self.j == other.j:
            ans = []
            for a in range(self.i):
                tmp = []
                for b in range(self.j):
                    tmp.append(self.matrix[a][b] - other.matrix[a][b])
                ans.append(tmp)

            m = Matrix(matrix=ans)
            return m
        else:
            print("Matrices having different number of rows and columns cannot be subtracted")

    def __mul__(self, other):
        if self.i == other.j and self.j == other.i:
            ans = []
            tp = other.transpose()
            for a in range(self.i):
                tmp = []
                for b in range(other.j):
                    sum = 0
                    for c in range(other.j):
                        sum += self.matrix[a][c] * tp.matrix[b][c]
                    tmp.append(sum)
                ans.append(tmp)

            m = Matrix(matrix=ans)
            return m
        else:
            print("Matrices having invalid number of rows and columns for multiplication")


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
while True:
    try:
        i = int(input("Enter the number of rows in B: "))
        j = int(input("Enter the number of columns in B: "))
        break
    except ValueError:
        print("Invalid Number \n\n")
print("Enter the elements for matrix B")
b = Matrix()
b.set_matrix(i, j)

index = 9

while index != 0:
    print("Please select an option by entering corresponding index and 0 to quit\n")
    print("1) Addition of two matrices")
    print("2) Subtraction of two matrices")
    print("3) Multiplication of two matrices")
    print("4) Transpose of a matrix\n")

    index = input("Select an option: ")
    try:
        index = int(index)
    except ValueError:
        print("Invalid Selection \n\n")
        continue

    if index == 1:
        print("Addition of A and B is")
        print(a + b)
        print()
    elif index == 2:
        print("Subtraction of A and B is")
        print(a - b)
        print()
    elif index == 3:
        print("Multiplication of matrices A and B is")
        print(a * b)
        print()
    elif index == 4:
        print("Transpose of A is:\n", a.transpose(), "\nTranspose of B is:\n", b.transpose(), sep="")
        print()
    elif index == 0:
        break
    else:
        print("Invalid Selection \n\n")
