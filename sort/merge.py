#!/usr/bin/env python

from pdb import set_trace

def main(*args):
    l = [int(i) for i in args]
    print ("Before: %s" % " ".join(["%3d" % i for i in l]))
    l2 = merge(l)
    print ("Result: %s" % " ".join(["%3d" % i for i in l2]))

def merge(arr):
    if len(arr) == 1:
        return arr

    ret = []
    m = len(arr) / 2

    left = merge(arr[:m])
    right = merge(arr[m:])

    l, r = 0, 0
    while l < len(left) and r < len(right):
        if left[l] <= right[r]:
            ret.append(left[l])
            l += 1
        else:
            ret.append(right[r])
            r += 1

    trailing = left[l:] if l < len(left) else right[r:]
    return ret + trailing

if __name__ == '__main__':
    from sys import argv
    main(*argv[1:])
