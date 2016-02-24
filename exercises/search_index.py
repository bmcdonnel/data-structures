import sys

def search_index(nums, target):
    if len(nums) == 1:
        return 1 if nums[0] < target else 0

    i = len(nums) / 2

    if nums[i] == target:
        return i
    elif nums[i] > target:
        return search_index(nums[:i], target)
    else:
        return i + search_index(nums[i:], target)

if __name__ == '__main__':
    result = search_index([int(x) for x in sys.argv[2:]], int(sys.argv[1]))

    print '{} -> index {}'.format(sys.argv[1], result)

