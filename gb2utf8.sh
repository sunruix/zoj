#!/bin/bash

IFS=$'\n'

# If 2 arguments are given, the second is the new filename
function conv {
    file="$1"
    newfile="$1"
    if [ $# > 1 ]; then
        newfile="$2"
    fi

    encoding=$(file --mime-encoding "$file")
    if [[ ! "$encoding" =~ "utf-8" ]]; then
        $(iconv "$file" -f gb18030 -t utf-8 -o "$newfile")
    fi
}

# Take one argument as filename's suffix
function conv_by_suffix {
    for file in $(ls | grep "$1$"); do
        newfile="$(file%.$1).utf8.$1"
        conv $file $newfile
    done
}

# Take one argument as filename's suffix
function conv_recrusive {
    for file in $(ls -1A); do
        if [ -d "$file" ]; then
            cd "$file"
            conv_recrusive "$1"
            cd "../"
        fi
    done
    conv_by_suffix "$1"
}

for file in $@; do
    conv "$file" "$file"
done
