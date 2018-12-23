import sys

def count_set_bits(number):
    count = 0

    while number:
        print(number)
        count += (number & 1)
        number = number >> 1

    return count

# determining if an integer is a power of two is just a special
# case of this algorithm
def count_set_bits_fast(number):
    count = 0 

    while number:
        print(number)
        count += 1
        number = number & (number - 1)
    
    return count

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m count_set_bits <an integer>")
        sys.exit(0)

    number = int(sys.argv[1])

    num_set_bits = count_set_bits_fast(number)

    print("{} has {} bit(s) set".format(number, num_set_bits))
