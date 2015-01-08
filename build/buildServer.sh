gcc -c ../server/streetViewAPI/streetViewAPI.c
gcc -c ../server/main.c
gcc streetViewAPI.o main.o -lcurl -o server
rm streetViewAPI.o main.o
./server