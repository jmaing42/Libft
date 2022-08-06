#!/bin/sh

printf "# script-generated file list\n"

printf "OBJS := %s\n" "$(cd src && find . -name "*.c" | grep -v "_bonus" | sed 's/\.c$/.o/' | cut -c 3- | xargs)"
printf "OBJS_BONUS := %s\n" "$(cd src && find . -name "*.c" | grep "_bonus" | sed 's/\.c$/.o/' | cut -c 3- | xargs)"

printf "\n"

cat template.mk

printf "\n# dependencies\n"

cd src && find . -name "*.c" | cut -c 3- | sort | xargs clang -MM -MG
