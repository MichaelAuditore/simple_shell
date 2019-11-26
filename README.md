# Simple Shell

# Description
Create a function that works like sh(dash command interpreter) for the required cases.

---

#  1. Basic command line Interpreter

Write a UNIX command line interpreter of one word.

    Handle command lines without arguments
    Display a prompt and wait for the user to type a command.
    A command line always ends with a new line.
    The prompt is displayed again each time a command has been executed.
    
# 2. Command line Interpreter with arguments

Write a UNIX command line interpreter with more arguments.

    Handle command lines with arguments
    
# 3. Handle the PATH

 Handle the Global Environment PATH variable to search and execute any command with arguments or options
 
     Handle the PATH
   
# 4. Create an Exit for shell

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
    
    #cisfun ls
    holamundo.js  index.html styles.css
    #cisfun ^C
    #cisfun exit
    miguel~/shell$

# 5. Handle CTRL+C

Handle Ctrl+C: your shell should not quit when the user inputs ^C

     #cisfun ^C
     #cisfun ^C
     #cisfun ^C
     #cisfun exit
     miguel~/shell$
# 6. Env

Implement the env built-in, that prints the current environment
    
    miguel@ubuntu:~/shell$ ./simple_shell
    #cisfun$ env
    USER=miguel
    LANGUAGE=en_US
    SESSION=ubuntu
    COMPIZ_CONFIG_PROFILE=ubuntu
    SHLVL=1
    HOME=/home/miguel
    C_IS=Fun_:)
    DESKTOP_SESSION=ubuntu
    LOGNAME=miguel
    TERM=xterm-256color
    PATH=/home/miguel/bin:/home/miguel/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    DISPLAY=:0
    #cisfun$ exit
    miguel@ubuntu:~/shell$ 

## EXAMPLE

You can use compile all files to generate your own executable:
In your shell: Type the name of executable(e.g. ./hsh)

    miguel@ubuntu:~/shell$ ./hsh
    #cisfun$ "You can start to type something to evaluate"
    #cisfun$ ls
    holamundo.js  index.html styles.css
    #cisfun$
## RETURN VALUE

If command exists and arguments is OK, this is execute and display correct output in the bash, or show error message if not found the file or directory of command or arguments
## Man file

## EXIT PROGRAM

You can use Ctrl+D or writing exit in the shell to finish the program


man_1_simple_shell (Open it in linux using man command (e.g. man ./man_1_simple_shell))
## AUTHORS
Angel Pedroza Cardenas [AngelPedroza] <https://github.com/AngelPedroza>
Miguel Parada [Michael-Auditore] <https://github.com/MichaelAuditore>