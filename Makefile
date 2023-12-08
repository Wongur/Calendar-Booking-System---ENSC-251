#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o mergedList.o testingdriver.o
	g++ -g -o main main.o student.o mergedList.o testingdriver.o

#compile the main.cpp to main.o
main.o: main.cpp student.hpp mergedList.hpp testingdriver.hpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp

#compile the studentList.cpp to studentList.o

mergedList.o: mergedList.cpp mergedList.hpp
	g++ -g -c mergedList.cpp

testingdriver.o: testingdriver.cpp testingdriver.hpp
	g++ -g -c testingdriver.cpp

#remove built files
clean:
	rm -rf main main.o student.o a.out mergedList.o testingdriver.o *~
