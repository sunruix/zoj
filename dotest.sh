#/bin/bash

exec_file="a.out"
case_file="input"

if [[ $# -gt 0 ]]; then
    exec_file="$1"
    if [[ $# -gt 1 ]]; then
        case_file="$2"
    fi
fi
"./$exec_file" < "$case_file"
echo "====================================================="
exec_status=$(ls -l "$exec_file")
case_status=$(ls -l "$case_file")
while true; do
    new_exec=$(ls -l "$exec_file")
    new_case=$(ls -l "$case_file")
    if [[ $new_exec != $exec_status || $new_case != $case_status ]]; then
        exec_status=$new_exec
        case_status=$new_case
        "./$exec_file" < "$case_file"
        echo "====================================================="
    fi
    sleep 1
done

