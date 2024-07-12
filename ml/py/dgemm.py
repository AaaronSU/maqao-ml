n = 1000
A = [[j for j in range(n)] for _ in range(n)]
B = [[j*2 for j in range(n)] for _ in range(n)]
C = [[None for _ in range(n)] for _ in range(n)]

# print(A)
# print(B)
# print(C)

for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][k] = A[i][j] * B[j][k]

# print(A)
# print(B)
# print(C)