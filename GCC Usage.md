1.Use a text editor to create the C source code.
Type the command 
```
gedit hello.c
```
and enter the C source code below:
```
#include <stdio.h>
main() {
 printf("Hello World\n");
}
```
Close the editor window.

2.Compile the program.
Type the command
```
gcc -o hello hello.c
```
This command will invoke the GNU C compiler to compile the file hello.c and output (-o)
the result to an executable called hello. 

3.Execute the program.
Type the command
```
./hello
```
This should result in the output
```
Hello World
```

5.Optional step
In order to avoid the./ prefix each time a program is to be executed, insert the following as
the last line in the file .profile (located in your home folder):
```
export PATH=.:$PATH
```
This step needs only to be done once
