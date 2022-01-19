#!/bin/bash

IFS=$'\n'

function conv {
    file = "$1"
    newfile = "$1"
    if [ $# > 1 ]; then
        newfile = "$2"
    fi

    encoding=$(file --mime-encoding "$file" | grep -o '[^ ]*$')
    if [ "$encoding" != "utf-8" ]; then
        $(iconv "$file" -f gb18030 -t utf-8 -o "$newfile")
    fi
}

function conv_by_ext {
    for file in $(ls | grep "$1$"); do
        encoding=$(file --mime-encoding "$file" | grep -o '[^ ]*$')
        if [ "$encoding" != "utf-8" ]; then
            f = $(ls "$file" grep '\(.*\.\)*' -o)
            conv $file "$f.utf8.$1"
        fi
    done

function conv_recrusive {
    for file in $(ls -1A); do
        if [ -d "$file" ]; then
            cd "$file"
            conv_recrusive "$1"
            cd "../"
        fi
    done
    conv_by_ext "$1"
}

for file in $@; do
    conv "$file" "$file"
done