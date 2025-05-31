# Boolean-Function-Checker
This is a program written in C to check boolean algebra functions. At the moment, equations can only be hand-jammed into the function.

# Compilation Instructions
    gcc boolean.c -o exec -lm
The code above compiles the .c file and outputs an executable file named "exec." The "-lm" is written in case you get a compilation error, `undefined reference to 'pow'` in the terminal.

# How it works
This program generates an array of booleans to input into a boolean algebra function of your choice. This array of booleans is generated and modified based on the number of variables you plan to test. The output is a truth table written out like a .csv for easy access and copying over to a cell sheet. As mentioned above, you will need to edit the `alg_function` to test your own boolean function.

# alg_function
When editing this function, be sure that the algebraic expression is properly written. Be sure to properly represent each variable with the corresponding `index[i]` value. For example, if your function is the following:
> F = (A · B) + NOT(C)

Write into the `return` line like this:

    return (char)(index[0] * index[1]) + !index[2]; 

Don't forget the `(char)` cast.

At the moment, the `alg_function` takes a second parameter for the number of variables being used. I plan to expand on this function in the future. I would like to implement a way to interpret a string. This string would be the function that the user would like to test.
