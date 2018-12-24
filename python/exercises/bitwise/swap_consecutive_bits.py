import sys

def swap_consecutive_bits(number, position_a, position_b, num_bits):
    # a/b diff is the least significant portion of this result
    ab_diff = (number >> position_a) ^ (number >> position_b)

    # mask off just the number of bits we care about
    ab_diff = ab_diff & ((1 << num_bits) - 1)

    # shift that diff to position a and position b
    ab_swap_mask = ((ab_diff << position_a) | (ab_diff << position_b))
    
    # return the masked version of number
    return number ^ ab_swap_mask

if __name__ == "__main__":
    if len(sys.argv) < 5:
        print("usage: python -m swap_consecutive_bits <an integer> <position a> <position b> <number of bits to swap>")
        sys.exit(0)

    number = int(sys.argv[1])
    position_a = int(sys.argv[2])
    position_b = int(sys.argv[3])
    num_bits = int(sys.argv[4])

    swapped = swap_consecutive_bits(number, position_a, position_b, num_bits)

    print(swapped)
