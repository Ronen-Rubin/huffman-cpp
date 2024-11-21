# Recreate the output folder to remove old build files
rm -rf dist
mkdir dist

g++ ./src/main.cpp ./src/counter.cpp ./src/files.cpp -o ./dist/huffman.exe
