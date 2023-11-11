#!/bin/bash

if [ $# -ne 2 ]; then
    exit 1
fi

echo  "$1" > $2
