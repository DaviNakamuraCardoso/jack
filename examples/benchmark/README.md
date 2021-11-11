# Benchmark 
## Python vs Jack

### Sorting
For the first test, we look at bubble sort and the default sorting methods

| Algorithm | Time |
| :--- | :--- | 
Jack Standard Sort | 0.002s |
Jack Bubble Sort | 0.014s |
Python Standard Sort | 0.038s |
Python Bubble Sort | 0.042s |


```Python
def main():
    a = list(range(100, 0, -1))

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
```
