import sys
from exercises.common.node import Node

def validate_bst(node, lower_limit=None, upper_limit=None):
    if node is None:
        return True

    if lower_limit is not None and node.value <= lower_limit: return False
    if upper_limit is not None and node.value >= upper_limit: return False

    left_is_valid = validate_bst(node.left, lower_limit, node.value)

    if not left_is_valid: return False

    return validate_bst(node.right, node.value, upper_limit)

if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    valid = validate_bst(tree)

    if valid:
        print("Tree is valid")
    else:
        print("Tree is NOT valid")
