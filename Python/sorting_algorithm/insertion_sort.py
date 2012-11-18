def insertion_sort(arr, size):
    for x in arr:
        print x,
    return arr


sortarr = insertion_sort
arr = [0, 8, 1, 6, 3, 2, 7, 5, 9, 4]
sortarr(arr, len(arr))
