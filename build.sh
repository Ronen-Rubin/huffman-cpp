# Recreate the output folder to remove old build files
rm -rf dist
mkdir dist

"C:\Program Files\LLVM\bin\clang++.exe" $(find src -name "*.cpp") -o ./dist/huffman.exe
