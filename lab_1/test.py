
array = [1,34,6,7,8,9,34,5,563,34]
print array

j = 0
for a in array:
    i = array.index(a)
    key = array[i]
    j = i - 1
    while (j >= 1 and array[j] > key):
        array[j+1] = array[j]
        j -= 1
    array[j] = key

print array

