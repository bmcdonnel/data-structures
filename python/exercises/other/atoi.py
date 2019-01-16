import sys

def atoi(integer_string):
    result = 0
    i = 0
    is_negative = integer_string[0] == "-"

    if is_negative:
        if len(integer_string) == 1:
            raise Exception("Invalid integer string")
        i += 1

    while i < len(integer_string):
        result *= 10

        char = ord(integer_string[i])

        if char < ord("0") or char > ord("9"):
            raise Exception("Invalid character {} in column {}".format(char, i))

        result += char - ord("0")

        i += 1

    if is_negative:
        result *= -1

    return result

if __name__ ==  "__main__":
    if len(sys.argv) != 2:
        print("usage: python -m atoi <integer>")
        sys.exit(0)

    result = atoi(sys.argv[1])

    print("integer value: {}".format(result))
