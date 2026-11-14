# dsa-cpp-practice (Second Year)

Data structures and algorithms practices in C++ from my second year of Software Engineering.

## Contents

- `data-structures/stack-project.cpp`: stack-based expression machine. Reads the instructions PUSH, ADD, SUB, MUL, DIV, SWAP, DUP and END, and builds the infix, postfix and prefix forms of an expression. Written for a university data structures assignment (operands are single letters A-Z).

## Build and run

    g++ -Wall -Wextra data-structures/stack-project.cpp -o stack
    ./stack.exe

Then type the instructions one per line, ending with END. Example input:

    PUSH A
    PUSH B
    ADD
    END

Output:

    Infix: (A+B)
    Postfix: AB+
    Prefix: +AB
