#!/bin/bash

while true; do
    ans1=$("./1047")
    ans2=$("./a.out")
    if [[ $ans1 -ne $ans2 ]]; then
        echo "ERROR $ans1 $ans2"
        `cp input input1`
    fi
    sleep 2
done
