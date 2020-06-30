def _range(n):
    t = 0
    if n % 3 == 1:
        t = ((n+2)/3)
    elif n%3 == 2:
        t = ((n+1)/3)
    else:
        t=((n)/3)
    return t*t 

def check(A, i, j, NUM, dim):
    if ((i>=0 and i<dim) and (j>=0 and j<dim) and A[i][j]==NUM):
        return 1
    return 0


def GridSearch(A, NUM, dim):
    flag = False
    f_i = f_j = None
    t = int(_range(dim))
    for i in range(1, t+1, 3):
        for j in range(1, t+1, 3):
            if check(A, i-1, j-1, NUM, dim):
                flag = True
                f_i = i-1
                f_j = j-1
                break
            if check(A, i-1, j, NUM, dim):
                flag = True
                f_i = i-1
                f_j = j
                break
            if check(A, i, j-1, NUM, dim):
                flag = True
                f_i = i
                f_j = j-1
                break
            if check(A, i-1, j+1, NUM, dim):
                flag = True
                f_i = i-1
                f_j = j+1
                break
            if check(A, i, j, NUM, dim):
                flag = True
                f_i = i
                f_j = j
                break
            if check(A, i, j+1, NUM, dim):
                flag = True
                f_i = i
                f_j = j+1
                break
            if check(A, i+1, j, NUM, dim):
                flag = True
                f_i = i+1
                f_j = j
                break
            if check(A, i+1, j+1, NUM, dim):
                flag = True
                f_i = i+1
                f_j = j+1
                break
        if flag:
            break

    return flag, f_i, f_j

if __name__ == "__main__":
    A = [[12,2,31,44],[5,36,7,82],[9,310,121,132],[313,145,515,616]]

    SearchNumber = 515
    
    found, i, j = GridSearch(A,SearchNumber, len(A))

    if found:
        print(i,",",j)
    else:
        print("Not Found")