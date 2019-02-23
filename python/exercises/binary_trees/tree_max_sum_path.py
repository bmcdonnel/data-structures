import sys
from exercises.common.node import Node

def max_root_leaf_sum(node, path=list()):
    if node is None:
        return 0, path

    left_sum, left_path = max_root_leaf_sum(node.left, path)
    right_sum, right_path = max_root_leaf_sum(node.right, path)

    if left_sum >= right_sum:
        max_sum = left_sum
        max_path = left_path
    else:
        max_sum = right_sum
        max_path = right_path

    return (max_sum + node.value, [node] + max_path)

def max_any_path_sum(root):
    def _max_any_path_sum(node):
        if node is None:
            return 0

        left_sum = _max_any_path_sum(node.left)
        right_sum = _max_any_path_sum(node.right)

        value = max(
            left_sum + node.val + right_sum,
            left_sum + node.val,
            right_sum + node.val,
            node.val,
        )

        max_sum[0] = max(value, max_sum[0])

        return max(left_sum + node.val, right_sum + node.val, node.val)

	max_sum = [-2**31]
	_max_any_path_sum(root)

	return max_sum[0]


if __name__ ==  "__main__":
    values = input("Enter tree (implicit ordering; use 'x' for empty node): ").strip().split(" ")
    tree = Node.build_from_implicitly_ordered_list(values)

    max_sum, max_path = max_root_leaf_sum(tree)

    print("Max sum path is {} with path:".format(max_sum))
    print([x.value for x in max_path])
