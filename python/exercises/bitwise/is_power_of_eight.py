import sys

# Given a number, check if it is a power of 8.

def is_power_of_two(number):
    return (number & (number - 1)) == 0

def is_power_of_eight(number):
    if not is_power_of_two(number):
        return False

    bit_pos = 0

    while number > 1:
        number = number >> 1
        bit_pos += 1

    return bit_pos % 3 == 0

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m find_odd_occuring_element <list of integer>")
        sys.exit(0)

    number = int(sys.argv[1])

    result = is_power_of_eight(number)

    if result:
        print("{} is a power of eight".format(number))
    else:
        print("{} is NOT a power of eight".format(number))
