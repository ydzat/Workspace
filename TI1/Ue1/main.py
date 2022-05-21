import os

data_list = [3,6,7,10,15,16,17,23,42,43,45,54,76,77,100]

def bi_search(data_list, val):
    low = 0
    high = len(data_list) - 1
    while low<=high:
        mid = (low + high)//2
        print(data_list[mid])
        if data_list[mid] == val:
            return mid
        elif data_list[mid] > val:
            high = mid - 1
        elif data_list[mid] < val:
            low = mid + 1
    return None

ans = bi_search(data_list, 16)

print(ans)