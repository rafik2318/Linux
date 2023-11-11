#!/bin/bash

if [ $# -ne 2 ]; then
    exit 1
fi

if [ $1 -gt $2 ]; then
    echo "true";
else echo "false"
fi


