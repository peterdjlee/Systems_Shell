# Systems_Shell
Kevin Li and Peter Lee
<br>
Period 10

<h2> Features </h2>
<ul>
<li> forks and executes commands </li>
<li> has a nice greeting when you open the shell! </li>
<li> handles cd and exit </li>
<li> displays working directory, like bash </li>
<li> can execute multiple commands on one line separated with semicolon (";") </li>
<li> says something nice when you quit shell! </li>
</ul>

<h2> Attempted </h2>
<ul>
<li> handle multiple commands on one line when semicolons are surrounded with spaces, like " ; " instead of just ";" </li>
<li> redirection and pipes </li>
</ul>

<h2> Bugs </h2>
<ul>
<li> Very occasionally the parser fails and cannot read the commands correctly. We tested it, and every time it happens, it can't read a certain character and reads it as a space. </li>
<li> Cannot handle multiple commands on one line when semicolon is surrounded by spaces. </li>
<li> If something that is not a command is entered into the shell, it does not work. </li>
</ul>

<h2> Files and Function Headers </h2>
<h3> main.c </h3>
<h3> shell.c </h3>
