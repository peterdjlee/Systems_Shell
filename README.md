# Systems_Shell
Kevin Li and Peter Lee
<br>
Period 10

<h2> Features </h2>
<ul>
<li> Forks and executes commands </li>
<li> Has a nice greeting when you open the shell! </li>
<li> Handles cd and exit </li>
<li> Displays working directory, like bash </li>
<li> Can execute multiple commands on one line separated with semicolon (";") </li>
<li> Says something sad but cute when you quit shell! </li>
<li> When you do something bad in the shell, it will print out bash-like errors using errno </li>
<li> 'magic' can hide or show your working directory </li>
</ul>

<h2> Attempted </h2>
<ul>
<li> Handle multiple commands on one line when semicolons or commands are surrounded with spaces, like " ; " instead of just ";" </li>
<li> Redirection and pipes </li>
</ul>

<h2> Bugs </h2>
<ul>
<li> Very occasionally the parser fails and cannot read the commands correctly. We tested it, and every time it happens, it can't read a certain character and reads it as a space. </li>
<li> Commands cannot be executed if there are any spaces regardless of usage of semicolons </li>
</ul>

<h2> Files and Function Headers </h2>
<h3> main.c </h3>

<h3> shell.c </h3>

```c
char ** parse_args(char * line, char delimiter)
```
  <ul>
  <li>Description:</li>
    <ul>
      <li>Parses the given string using the given delimiter</li>
    </ul>
  <li>Arguments:</li>
    <ul>
      <li>char * line -> A pointer to the original string</li>
      <li>char delimiter -> The character that is going to be used to parse the string</li>
    </ul>
  <li>Return Value:</li>
    <ul>
      <li>A char ** which consists of the parsed strings</li>
    </ul>
  </ul>
  
  ```c
void exec_one(char ** args)
  ```
  <ul>
  <li>Description:</li>
    <ul>
      <li>Forks off a child process and the child process calls execvp to execute the given command</li>
    </ul>
  <li>Arguments:</li>
    <ul>
      <li>char ** args -> Command line arguments that should be executed</li>
    </ul>
  <li>Return Value:</li>
    <ul>
      <li>N/A</li>
    </ul>
  </ul>

  ```c
void redir_in(char ** args)
  ```
  <ul>
  <li>Description:</li>
    <ul>
      <li>Implements redirecting in by writing to a file</li>
    </ul>
  <li>Arguments:</li>
    <ul>
      <li>char ** args -> A pointer to the original string</li>
    </ul>
  <li>Return Value:</li>
    <ul>
      <li>N/A</li>
    </ul>
  </ul>
