g++ -I project tests/tests.cpp project/src/*.c -lgtest -lpthread
valgrind --tool=memcheck --leak-check=full -s --track-origins=yes ./a.out