def insertion_sort(arr, size):
    for x in range(1, size):
        tmp = arr[x]
        while x > 0 and tmp < arr[x-1]:
            arr[x] = arr[x-1]
            x = x - 1
        arr[x] = tmp
    return arr

def shell_sort(arr, size):
    gap = size/2
    while gap > 0:
        for x in range(gap, size, gap):
            tmp = arr[x]
            while x > 0 and tmp < arr[x-gap]:
                arr[x] = arr[x-gap]
                x = x - gap
            arr[x] = tmp
        gap = gap/2
    return arr

def mergesorted(arr, tmpArr, l, rstart, r):
    tmp = l
    lend = rstart - 1
    elem = r - l + 1
    while l <= lend and rstart <= r:
        if arr[l] < arr[rstart]:
            tmpArr[tmp] = arr[l]
            tmp = tmp + 1
            l = l + 1
        else:
            tmpArr[tmp] = arr[rstart]
            tmp = tmp + 1
            rstart = rstart + 1
    while l <= lend:
        tmpArr[tmp] = arr[l]
        tmp = tmp + 1
        l = l + 1
    while rstart <= r:
        tmpArr[tmp] = arr[rstart]
        tmp = tmp + 1
        rstart = rstart + 1

    x = 0
    while x < elem:
        arr[r] = tmpArr[r]
        r = r - 1
        x = x + 1

def mergesort(arr, tmpArr, l, r):
    c = (l+r)/2
    if l < r:
        mergesort(arr, tmpArr, l, c)
        mergesort(arr, tmpArr, c+1, r)
        mergesorted(arr, tmpArr, l, c+1, r)

def merge_sort(arr, size):
    tmpArr = list(range(0, size))
    mergesort(arr, tmpArr, 0, size-1)
    return arr

def median3(arr, l, r):
    c = (l+r)/2
    if arr[l] > arr[c]:
        arr[l], arr[c] = arr[c], arr[l]
    if arr[c] > arr[r]:
        arr[c], arr[r] = arr[r], arr[c]
    if arr[l] > arr[r]:
        arr[l], arr[r] = arr[r], arr[l]
    arr[c], arr[r-1] = arr[r-1], arr[c]
    return arr[r-1]
        

def quicksort(arr, l, r):
    if l + 10 <= r:
        tmp = median3(arr, l, r)
        i = l + 1
        j = r - 1 - 1
        while(True):
            while arr[i] < tmp: i += 1
            while arr[j] > tmp: j -= 1
            if i < j:
                arr[i], arr[j] = arr[j], arr[i]
            else:
                break
        arr[i],arr[r-1] = arr[r-1],arr[i]
        quicksort(arr, l, i-1)
        quicksort(arr, i+1, r)
    else:
        insertion_sort(arr[l:], r-l+1)
 

def quick_sort(arr, size):
    quicksort(arr, 0, size-1)
    return arr


arr = [5, 15, 8, 3, 2, 17, 10, 6, 14, 19, 1, 13, 0, 12, 7, 4, 16, 11, 18, 9]
print quick_sort(arr, len(arr))
