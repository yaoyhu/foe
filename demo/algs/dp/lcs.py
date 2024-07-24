def lcs(s1, s2) -> str:
    """
    if s1[i] != s2[j]:
        L(i, j) = max(L(i, j+1) + L(i+1, j))
    else:
        L(i, j) = 1 + L(i+1, j+1)
    return: L(0, 0)
    """
    len1 = len(s1)
    len2 = len(s2)
    # Matrix: (len1+1) * (len2+1), +1 for 0
    L = [[0] * (len2 + 1) for _ in range(len1 + 1)]

    for i in reversed(range(len1)):
        for j in reversed(range(len2)):
            if s1[i] == s2[j]:
                L[i][j] = 1 + L[i + 1][j + 1]
            else:
                L[i][j] = max(L[i + 1][j], L[i][j + 1])
    return L[0][0]


print(lcs("hieroglyphology", "michaelangelo"))
