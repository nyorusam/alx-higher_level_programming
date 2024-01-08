#!/usr/bin/python3

def add_tuple(tuple_a, tuple_b):
    result = tuple(x + y for x, y in zip(tuple_a, tuple_b)) + tuple(tuple_a[len(tuple_b):] + tuple_b[len(tuple_a):])
    return result

tuple_a = (1, 89)
tuple_b = (88, 11)

new_tuple = add_tuple(tuple_a, tuple_b)
print(new_tuple)

print(add_tuple(tuple_a, (1,)))

