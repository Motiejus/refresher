#!/usr/bin/env python
def main(*args):
    l = [int(i) for i in args]
    print ("Before: %s" % " ".join(["%3d" % i for i in l]))
    l2 = quick(l)
    print ("Result: %s" % " ".join(["%3d" % i for i in l2]))

def quick(arr):
    if arr == []:
        return []
    pivot = arr.pop()
    less, more = [], []
    for i in arr:
        if i < pivot:
            less.append(i)
        else:
            more.append(i)
    less = quick(less)
    more = quick(more)

    return less + [pivot] + more

if __name__ == '__main__':
    from sys import argv
    main(*argv[1:])
