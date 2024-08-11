#!/bin/bash
# About: build PandaRuntimelib
# this is PandaRuntimeLib build script
# @copyright (c) 2021-2022 PandaGroup
# @author PandaGroup
# @version 1.0.0
# C version: c11
# compiler: gcc
echo "build..."
echo "[BUILDING]" > build.log
file_list=("PStringw" "PDataTypeConversionw" "Pprintw" "PDataStructurew" "PFilew" "PBitsetw" "PTimew" "PColor" "PLogw" "PMemory" "PFormw")
position_list=("./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/" "./src/mods/")
pg=("-" "\\" "|" "/")
rm -rf ../build/PandaRuntimelib
mkdir ../build/PandaRuntimelib
cp -r ./* ../build/PandaRuntimelib
rm -rf ../build/PandaRuntimelib/lib/*.so
rm -rf ../build/PandaRuntimelib/src
clear_h(){
    for((i_Clear = 0; i_Clear < $1; i_Clear++));do
        printf " " 
    done
}

for ((i = 0; i < ${#file_list[@]}; i++));do
    File=${position_list[$i]}${file_list[$i]}.c
    if [ $i == 0 ];
        then
            gcc -shared -fpic -o ../build/PandaRuntimelib/lib/${file_list[$i]}.so $File -std=c11
        else
            gcc -shared -fpic $File ../build/PandaRuntimelib/lib/*.so -o ../build/PandaRuntimelib/lib/${file_list[$i]}.so -std=c11
    fi
    printf "\r${pg[`expr $i % 4`]} build:${file_list[$i]} [`expr $i + 1`/${#file_list[@]}]"
    clear_h `expr ${#file_list[$i]} + 8`
    echo "build ${file_list[$i]} done [OK] [$i/${#file_list[@]}]" >> build.log
done
printf "\nDone [OK]"
rm -rf ./lib/*.*
cp -rf ../build/PandaRuntimelib/lib/*.so ./lib