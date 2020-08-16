# Ch05 Control Flow

## L.5.1 Control flow introduction

C++ provides **control flow statements** (also called *flow control statements*), which allow the programmer to change the CPU’s path through the program. 

### Halt

> Rule
>
> Only use std::exit() if there is no safe way to return from the main  function.  Don’t use it as an easy way out, you’ll leak resources.