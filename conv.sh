#!/bin/bash

IFS=$'\n'

function conv {
    for file in $(ls | grep 'cue$'); do
        encoding=$(file --mime-encoding "$file" | grep -o ':.*' | grep -o [[:alnum:]].*)
            if [ "$encoding" != "utf-8" ]; then
                encoding="gbk"
                len=$((${#file} - 4))
                newfile="${file::$len}.utf8.cue"
                $(iconv -f "$encoding" -t utf-8 "$file" > "$newfile")
            fi
    done

    for file in $(ls -1A); do
        if [ -d "$file" ]; then
            cd "$file"
            conv
            cd "../"
        fi
    done
}

conv
