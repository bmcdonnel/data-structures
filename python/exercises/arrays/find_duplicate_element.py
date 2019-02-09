import sys

def find_duplicate_element(array):
    seen = dict()

    for i, x in enumerate(array):
        if x in seen:
            return True, x, i
        else:
            seen[x] = i

    return False, None, None

if __name__ ==  "__main__":
    array = [int(x) for x in input("Enter a list of integers with a single duplicate: ").strip().split(" ")]

    found, value, index = find_duplicate_element(array)

    if found:
        print("Found duplicate {} at index {}".format(value, index))
    else:
        print("No duplicate found")
