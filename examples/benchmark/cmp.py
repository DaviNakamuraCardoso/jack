def main():
    a = list(range(1000, 0, -1))

    print(a)
#    bubble(a)
    a.sort()
    print(a)

def bubble(a):
    sorted = False
    while not sorted:
        sorted = True
        for i in range(0, len(a) - 1):
            if (a[i] > a[i + 1]):
                tmp = a[i]
                a[i] = a[i+1]
                a[i+1] = tmp
                sorted = False

if __name__ == '__main__':
    main()
