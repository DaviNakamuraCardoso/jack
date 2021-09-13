# The Jack Programming Language
## Compiler for an Object-Oriented Java-like Language

### Compilation Process
The Jack language is compiled in a two-tier process:
![Two tier compilation process. from the book *Compilers: Principles, Techniques and tools*](./compilation.png)

The code is first translated to an intermediate program (like Java's *bytecode* and C#'s *Intermediate Language*) and then a Virtual Machine Translator finishes the compilation process either by interpreting the VM code or by translating to the target's machine assembly language.  

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

### Hello, World

Hello world program in Jack

```Java
class Main {
    function void main() {
        do Output.printString("Hello, World");
        do Output.println();
        return;
    }
}

```

### Object Oriented features 

In Dog.jack:

```Java

class Dog {

    field int age, weight;
    field String name;

    constructor Dog new(int a, int w, String n) {
        let age = a;
        let weight = w;
        let name = n;  
        return this;
    }

    method void bark() {
        do Output.printString(name);
        do Output.printString(" says ");

        if (weigth < 20) {
            do Output.printString("woof, woof");
        } else {
            do Output.printString("WOOF, WOOF")
        }

        do Output.println();

        return;

    }
}

```

In Main.jack:
```Java
class Main {

    function main() {
        var Dog codie;

        let codie = Dog.new(2, 14, "Codie");
        do codie.bark();
        return;
    }
}

```
