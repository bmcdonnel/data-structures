import sys

def coroutine(func):
    def start(*args, **kwargs):
        coroutine_func = func(*args, **kwargs)
        next(coroutine_func)

        return coroutine_func

    return start

@coroutine
def grep(pattern):
    print("Looking for pattern {}".format(pattern))

    while True:
        line = (yield)
        if pattern in line:
            print("Found '{}'".format(pattern))

def main():
    pattern = input("Enter the desired pattern: ")

    grepper = grep(pattern)

    print("Enter lines to see if a match is found:")

    try:
        while True:
            line = input()
            grepper.send(line)
    except EOFError:
        pass
    except KeyboardInterrupt:
        pass
    finally:
        grepper.close()
        print()

if __name__ == "__main__":
    main()
