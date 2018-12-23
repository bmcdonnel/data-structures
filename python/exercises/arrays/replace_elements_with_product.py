import sys

# Given an array of integers, replace each element of the array with product of
#   every other element in the array without using division operator.
#
# For Example,
#   Input:  { 1, 2, 3, 4, 5 }
#   Output: { 120, 60, 40, 30, 24 }
#
#   Input:  { 5, 3, 4, 2, 6, 8 }
#   Output: { 1152, 1920, 1440, 2880, 960, 720 }

def replace_elements_with_product(array):
    left_products = [1] * len(array)
    right_products = [1] * len(array)

    # collect the products of all elements from the left excluding the current one
    for i in range(1, len(array)):
        left_products[i] = left_products[i - 1] * array[i - 1]

    # collect the product of all elements from the right excluding the current one
    for i in range(1, len(array)):
        right_products[-i - 1] = right_products[-i] * array[-i]

    # multiply the left and right products together
    for i in range(len(array)):
        array[i] = left_products[i] * right_products[i]

if __name__ ==  "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m replace_elements_with_product <list of integers>")
        sys.exit(0)

    array = [int(x) for x in sys.argv[1:]]

    print("input: {}".format(array))

    replace_elements_with_product(array)
    
    print("output: {}".format(array))
