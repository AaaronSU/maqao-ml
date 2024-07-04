#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'

PROGRAM="/home/user/macao-kitchen/ml/py/test.py"
PYTHON_COMPILER="/usr/bin/python3"
PYPY_COMPILER="/home/user/pycompilo/pypy3.10-v7.3.16-linux64/bin/pypy3"
INTELPYTHON_COMPILER="/home/user/intelpython3/bin/python3.9"

INTELPYTHON_OUTPUT_DIR="/home/user/macao-kitchen/ml/titanic-intelpython-report"
CPYTHON_OUTPUT_DIR="/home/user/macao-kitchen/ml/titanic-cpython-report"
PYPY_OUTPUT_DIR="/home/user/macao-kitchen/ml/titanic-pypy-report"

# echo "IntelPython is executing..."
# time ${INTELPYTHON_COMPILER} ${PROGRAM}
# echo "IntelPython finished execution."
# echo

# echo "CPython is executing..."
# time ${PYTHON_COMPILER} ${PROGRAM}
# echo "CPython finished execution."
# echo

# echo "PyPy is executing..."
# time ${PYPY_COMPILER} ${PROGRAM}
# echo "PyPy finished execution."

echo -e "${GREEN}Generating MAQAO report with intelpython compiler${NC}"
maqao OV -R1 xp=${INTELPYTHON_OUTPUT_DIR} --replace -c=intelpython_config.json
echo "finished generate report"

echo -e "${GREEN}Generating MAQAO report with cpython compiler${NC}"
maqao OV -R1 xp=${CPYTHON_OUTPUT_DIR} --replace -c=cpython_config.json
echo "finished generate report"

echo -e "${GREEN}Generating MAQAO report with pypy compiler${NC}"
maqao OV -R1 xp=${PYPY_OUTPUT_DIR} --replace -c=pypy_config.json
echo "finished generate report"