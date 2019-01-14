import sys

# C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
def n_choose_k(n, k):
    results = [[0 for j in range(k+1)] for i in range(n + 1)]

    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            if j == 0 or j == i:
                results[i][j] = 1
            else:
                results[i][j] = results[i - 1][j - 1] + results[i - 1][j]

    return results[n][k]

# C(n, k) is also a pascal triangle
def n_choose_k_optimized(n, k):
    results = [0 for i in range(k + 1)]
    results[0] = 1

    for i in range(1, n + 1):
        j = min(i, k)

        while j > 0:
            results[j] = results[j] + results[j - 1]
            j -= 1

    return results[k]

if __name__ ==  "__main__":
    if len(sys.argv) != 3:
        print("usage: python -m n_choose_k <n> <k>")
        sys.exit(0)

    n = int(sys.argv[1])
    k = int(sys.argv[2])

    result = n_choose_k_optimized(n, k)

    print("{} choose {} yields {} combinations".format(n, k, result))
