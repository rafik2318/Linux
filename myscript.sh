#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Error"
    exit 1
fi

arg=$1

mkdir workDir

echo "$arg" > message.txt
