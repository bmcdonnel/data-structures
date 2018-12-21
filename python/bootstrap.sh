#!/bin/bash

if [ -d "venv" ]; then
  rm -rf venv
fi

virtualenv --python=python3.6 venv
source venv/bin/activate

if [ -e "requirements.txt" ] && [ -s "requirements.txt" ]; then
  pip install -r requirements.txt
fi
