if [ -f "/home/alex/Documents/SW_Dew/Cpp/CodeTest/build/Makefile" ]; then
    echo "Makefile exists."
    cd build
    make
else 
    echo "/home/alex/Documents/SW_Dew/Cpp/CodeTest/build/Makefile does not exist."
    mkdir build
    cd build
    cmake ..
    make 
fi
