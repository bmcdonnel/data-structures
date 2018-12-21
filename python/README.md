# Python Exercises

## Running

Simply use the run script by passing it the name of the python module and any additional arguments needed. It will take care of bootstrapping the virtual environment and installing any dependencies.

```bash
bmcdonnel:python$ ./run.sh binary_search
bootstrapping virtual environment
Running virtualenv with interpreter /usr/local/bin/python3.6
Using base prefix '/usr/local/Cellar/python/3.6.4_4/Frameworks/Python.framework/Versions/3.6'
New python executable in /Users/bmcdonnel/github/data-structures/python/venv/bin/python3.6
Also creating executable in /Users/bmcdonnel/github/data-structures/python/venv/bin/python
Installing setuptools, pip, wheel...done.
Collecting pytest (from -r requirements.txt (line 1))
...
Installing collected packages: py, pluggy, six, atomicwrites, attrs, more-itertools, pytest
Successfully installed atomicwrites-1.2.1 attrs-18.2.0 more-itertools-4.3.0 pluggy-0.8.0 py-1.7.0 pytest-4.0.2 six-1.12.0
usage: python -m binary_search <desired value> <sorted list of integers>
bmcdonnel:python$
```
