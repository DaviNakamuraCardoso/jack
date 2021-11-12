# Benchmark 
## Python vs Jack

### Sorting
For the first test, we look at bubble sort and the default sorting methods

| Algorithm | Time | Elements
| :--- | :--- | :--- |  
Jack Standard Sort | 0.003s | 1000 |
Python Standard Sort | 0.038s | 1000 |


```Python
def main():
    a = list(range(1000, 0, -1))
    print(a)
    a.sort()
    print(a)

if __name__ == '__main__':
    main()
```
