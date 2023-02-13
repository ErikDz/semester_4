#!/bin/sh

indentation=""

subtree () {
    for item in "$1"/*; do
        if [ -d "$item" ]; then
            echo "${indentation}${item}"
            indentation="${indentation}  "
            subtree "$item"
            indentation="${indentation%  }"
        fi
    done
}

subtree .

