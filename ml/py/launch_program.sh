#!/bin/bash

PROGRAM="/home/user/macao-kitchen/ml/py/test.py"
PYTHON_COMPILER="/usr/bin/python3"
PYPY_COMPILER="/home/user/pycompilo/pypy3.10-v7.3.16-linux64/bin/pypy3"
INTELPYTHON_COMPILER="/home/user/intelpython3/bin/python3.9"

echo "IntelPython is executing..."
time ${INTELPYTHON_COMPILER} ${PROGRAM}
echo "IntelPython finished execution."
echo

echo "CPython is executing..."
time ${PYTHON_COMPILER} ${PROGRAM}
echo "CPython finished execution."
echo

echo "PyPy is executing..."
time ${PYPY_COMPILER} ${PROGRAM}
echo "PyPy finished execution."
