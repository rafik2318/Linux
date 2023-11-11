#!/bin/bash

if [ $# -ne 2 ]; then
    exit 1
fi


if [ $1 -eq 0 ]; then
    echo "false"

else
    if [ $2 -eq 0 ]; then
    echo "false"
    else echo "true"
    fi

fi

