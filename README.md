# The Jack Programming Language 
## Compiler and Virtual Machine

[toc] 

### The Jack Language 
Jack is an educational programming language created by [Shimon Schocken](https://shimonschocken.com) and [Noam Nisan](https://en.wikipedia.org/wiki/Noam_Nisan) for the course *The Elements of Computing Systems*, also known as [Nand2Tetris](https://nand2tetris.org), offered by [The Hebrew University of Jerusalem](https://en.wikipedia.org/wiki/Hebrew_University_of_Jerusalem). Students are asked to build their own compilers for this object-oriented language.

### Compilation 
The Jack language is compiled in a two-tier process:
![Two tier compilation process. from the book *Compilers: Principles, Techniques and tools*](./compilation.png)

The code is first translated to an intermediate program (like Java's *bytecode* and C#'s *Intermediate Language*) and then a Virtual Machine Translator finishes the compilation process either by interpreting the VM code or by translating to the target's machine assembly language.  


### Build (Linux Only)
On the parent directory: 
```console
$ sudo ./install.sh 
```


### Compilation 
#### Compile from Jack to VM
```Bash
$ ./dcc <path>
```

#### Interpret the VM code 
```Bash
$./jack <path>
```


### Hello, World

Hello world program in Jack

```JavaScript
class Main {
    function int main() {
        do Output.printf("Hello, World!\n");
        return 0;
    }
}

```

Save the file as Main.jack and run

```console
$ dcc .
```

This will compile all source files in the current folder. Run

```console
$ jack .
```

To interpret the VM files produced in the current folder

Output: 
```console
Hello, World!
```

### Features
Jack is a Turing-complete, object-oriented language, with most of the features that any modern language has, such as branching, loops, assignments, arrays, classes, methods, arithmetic operations and more.

### Syntax
Jack has a C-like syntax. Reserved words in Jack are:

|      |      |
| :------------- | :------------- |
| this       | field       |
| static | constructor       |
| method | function |
| int | char |
| boolean | var |
| let | do |
| while | if |
| else | return |
| true | false |
| null | void |

### Arrays 

```JavaScript

class Main {
    function int main() {
        var Array a;

        let a = Array.new(392, 32, 29, 3, 9);
        do a.sort();

        do Output.printf("%s is %i elements long.\n", a.to_s(), a.length());
        return 0;
    }
}

```

#### Output
```console
[3,9,29,32,392] is 5 elements long

```


### Object Oriented features 

In Dog.jack:

```JavaScript
class Dog {

    field int weight;
    field String name;

    constructor Dog new(int w, String n) {
        let weight = w;
        let name = n;  
        return this;
    }

    method void bark() {
        var String bark;

        if (weight < 20) {
            let bark = "woof, woof";
        } else {
            let bark = "WOOF, WOOF";
        }

        do Output.printf("%s says %s!\n", name, bark); 

        return;

    }
}

```

In Main.jack:
```JavaScript
class Main {

    function void main() {
        var Dog codie, fido;

        let codie = Dog.new(24, "Codie");
        let fido = Dog.new(12, "Fido");
        do codie.bark();
        do fido.bark();
        return;
    }
}

```

#### Compile && Run 
```Bash
$./dcc .
$./jack .
```

#### Output
```
Codie says WOOF, WOOF!
Fido says woof, woof!
```

