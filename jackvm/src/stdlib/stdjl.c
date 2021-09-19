#include <stdio.h>
#include <stdlib/stdio.h>
#include <stdlib/memory.h>
#include <stdlib/stdjl.h>
#include <tokenizer.h>


static Std library[] = {
    // Memory 
    (Std) {.name="Memory.alloc", .f=std_malloc}, 
    (Std) {.name="Memory.deAlloc", .f=std_free}, 
    
    // STD I/O
    (Std) {.name="Output.putc", .f=std_putc}, 
    (Std) {.name="Output.printf", .f=std_printf},
    (Std) {.name="Keyboard.getString", .f=std_getstring},

    // Files
    (Std) {.name="File.open", .f=std_open},
    (Std) {.name="File.close", .f=std_close},
    (Std) {.name="File.printf", .f=std_file_print},
    
    // String 
    (Std) {.name="String.new", .f=std_string}, 
    (Std) {.name="String.appendChar", .f=std_appendchar}, 
    
    // Arrays
    (Std) {.name="Array.new", .f=std_array} , 
    (Std) {.name="Array.fullArray", .f=std_full_array},
    (Std) {.name="Array.count", .f=std_array_count},
    (Std) {.name="Array.dispose", .f=std_array_dispose},
    (Std) {.name="Array.length", .f=std_array_length},
    (Std) {.name="Array.sort", .f=std_array_sort},

    // Time
    (Std) {.name="Clock.now", .f=std_clock}, 
    (Std) {.name="Clock.clocksPerSec", .f=std_clockspersec}, 

    // Math 
    (Std) {.name="Math.sqrt", .f=std_sqrt}
};


int stdlib(Source* s)
{
    for (int i = 0; i < sizeof(library) / sizeof(Std); i++)
    {
        add_map(s->indexes, library[i].name);
        s->labels[i+1] = library[i].f; 
    }
    s->stdcount = s->indexes->counter; 

    return 0;
}
