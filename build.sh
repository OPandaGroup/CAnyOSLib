#!/bin/bash
echo "build..."
echo "[BUILDING]" > build.log
file_list=("PStringw" "PDataTypeConversionw" "Pprintw" "PDataStructurew" "PFilew" "PBitsetw")
position_list=("./src/Core/widgets/" "./src/Core/widgets/" "./src/Core/widgets/" "./src/Core/widgets/" "./src/Core/widgets/" "./src/Core/widgets/")
rm -rf ../build/PandaRuntimelib
mkdir ../build/PandaRuntimelib
cp -r ./* ../build/PandaRuntimelib
rm -rf ../build/PandaRuntimelib/lib/*.so
rm -rf ../build/PandaRuntimelib/src
for ((i = 0; i < ${#file_list[@]}; i++));do
    echo "build ${file_list[$i]}"
    File=${position_list[$i]}${file_list[$i]}.c
    if [ $i == 0 ];
        then
            gcc -shared -fpic -o ../build/PandaRuntimelib/lib/${file_list[$i]}.so $File 
        else
            gcc -shared -fpic $File ../build/PandaRuntimelib/lib/*.so -o ../build/PandaRuntimelib/lib/${file_list[$i]}.so
    fi
    echo "done [$i/${#file_list[@]}]"
    echo "build ${file_list[$i]} done [OK] [$i/${#file_list[@]}]" >> build.log
done
rm -rf ./lib/*.*
cp -rf ../build/PandaRuntimelib/lib/*.so ./lib