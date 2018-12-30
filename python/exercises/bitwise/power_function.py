import sys

# Efficiently implement the power function.
# For example:
#  pow(-2, 10) = 1024
#  pow(-3, 4) = 81
#  pow(5, 0) = 1

def pow(base, exponent):
    result = 1

    for i in range(exponent):
        result *= base

    return result

def pow_recursive(base, exponent):
    if exponent == 0:
        print("returning 1")
        return 1

    # use integer division with // operator
    result = pow_recursive(base, exponent >> 2)
    print("result: pow({}, {}) = {}".format(base, exponent, result))

    if exponent & 1:
        # base is odd
        return base * result * result

    # base is even
    return result * result

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("usage: python -m power_function <base> <exponent>")
        sys.exit(0)

    base = int(sys.argv[1])
    exponent = int(sys.argv[2])

    result = pow(base, exponent)
    result_recursive = pow_recursive(base, exponent)

    print("pow({}, {}) = {}".format(base, exponent, result))
    print("pow_fast({}, {}) = {}".format(base, exponent, result_recursive))
