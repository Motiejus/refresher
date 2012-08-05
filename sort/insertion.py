def main(*args):
    l = [int(i) for i in args]
    l2 = insertion(l)
    print ("Result: %s" % l2)

def insertion(l):
    for i in range(len(l)):

        for j in range(i, 0, -1):
            if l[j] < l[j-1]:
                l[j], l[j-1] = l[j-1], l[j]
            else:
                break

    return l

if __name__ == '__main__':
    from sys import argv
    main(*argv[1:])
