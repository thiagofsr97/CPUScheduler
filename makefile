CC=g++
CFLAGS=-I -std=c++11
DEPS = FileUtil.h Process.h Scheduler.h Util.h
OBJ = main.o FileUtil.o Process.o Scheduler.o
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CPUScheduler: $(OBJ)
	g++ -o $@ $< $(CFLAGS)
