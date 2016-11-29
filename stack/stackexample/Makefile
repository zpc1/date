
CC=gcc
RM=rm
OBJS=llist.o stack.o scanner.o
TARGET=stack

$(TARGET):$(OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) -rf $(OBJS) $(TARGET)
