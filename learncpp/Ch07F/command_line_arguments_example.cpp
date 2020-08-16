#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "There are " << argc << " arguments:\n";

    for (int count{0}; count < argc; ++count)
    {
        std::cout << count << " " << argv[count] << '\n';
    }

    return 0;
}

// *Output example
/* 
$ ./command_line_arguments_example.out hello world !
There are 4 arguments:
0 ./command_line_arguments_example.out
1 hello
2 world
3 !

 $ ./command_line_arguments_example.out "Hello world!"
There are 2 arguments:
0 ./command_line_arguments_example.out
1 Hello world!
*/