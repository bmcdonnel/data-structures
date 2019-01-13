# Python Exercises
## Running

Simply use the run script by passing it the name of the python module and any additional arguments needed. It will take care of bootstrapping the virtual environment and installing any dependencies.

```bash
$> ./run.sh exercises.binary_search_trees.insertion
bootstrapping virtual environment
Running virtualenv with interpreter /usr/local/bin/python3.6
Using base prefix '/usr/local/Cellar/python/3.6.4_4/Frameworks/Python.framework/Versions/3.6'
New python executable in /Users/bmcdonnel/github/data-structures/python/venv/bin/python3.6
Also creating executable in /Users/bmcdonnel/github/data-structures/python/venv/bin/python
Installing setuptools, pip, wheel...done.
Collecting pytest (from -r requirements.txt (line 1))
...
...
Enter tree nodes in any order:  7 3 9 5 6 20 22 23 24 25 26 27                                

               27
          26
     25
          24
23
               22
          20
               9
     7
               6
          5
               3
Enter value to insert: 1

               27
          26
     25
          24
23
               22
          20
               9
     7
               6
          5
               3
                    1
Enter value to insert: ^D
$> ./run.sh exercises.graphs.a_star
Enter a maze line by line.
Use the following symbols separated by spaces:
 '+': starting point
 '.': open space
 'x': obstacle
 '*': ending point
Press CTRL+C to finish
+ . . . . x x x x x x *
x x . . . x x . . . . .
x x . . . x x . . x x x
. . . x . x x . . . x x
. . x x . x x . . . x x
. . x x x x x x x . . x
. . . x x x x . . . . x
. . x x x x . . . . x x
. . . . x x x . . . . x
. . . . x x . . . x x x
. . x x x x . . . x x x
. . . . . . . . x x x x
. . . . . . . . x x x x
x x x x x x x x x x x x
^C
+ o o o o x x x x x x *
x x . . o x x . o o o o
x x o o o x x . o x x x
. o o x . x x . o o x x
. o x x . x x . . o x x
. o x x x x x x x o . x
. o . x x x x o o o . x
. o x x x x . o . . x x
. o . . x x x o . . . x
. o . . x x o o . x x x
. o x x x x o . . x x x
. o o o o o o . x x x x
. . . . . . . . x x x x
x x x x x x x x x x x x
$>
```
