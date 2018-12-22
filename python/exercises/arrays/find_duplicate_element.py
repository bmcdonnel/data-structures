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
    if len(sys.argv) < 2:
        print("usage: python -m find_duplicate_element <list of integers with a single duplicate>")
        sys.exit(0)

    array = [int(x) for x in sys.argv[1:]]

    found, value, index = find_duplicate_element(array)

    if found:
        print("Found duplicate {} at index {}".format(value, index))
    else:
        print("No duplicate found")
