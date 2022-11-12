if [ ! -d "./build" ]; then
  mkdir build
fi

g++ -c src/test.cpp -o ./build/test.o
g++ -c src/test-runner.cpp -o ./build/test-runner.o
ar rvs ./build/libtesting.a ./build/test.o ./build/test-runner.o
rm -f ./build/*.o

