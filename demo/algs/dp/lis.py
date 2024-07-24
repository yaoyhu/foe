def lis(A: str) -> int:
    length = len(A)
    L = [1] * length
    for i in reversed(range(length)):
        L[i] = 1 + max((L[j] for j in range(i + 1, length) if A[j] > A[i]), default=0)
    return max(L)


assert lis("CARBOHYDRATE") == 5  # "ABORT"
