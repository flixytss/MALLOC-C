FILE=main.c
TOOLS=tools.s
OUTPUT=app.out
CC=gcc
OUT=out
ENTRY=src
DIS=diassemble

main: $(SRC)
	$(CC) $(ENTRY)/$(FILE) -o $(OUT)/$(OUTPUT)
run: main
	./$(OUT)/$(OUTPUT)
debug: main
	gdb ./$(OUT)/$(OUTPUT)
clean:
	rm -rf $(OUT)/$(OUTPUT)
.PHONY: main run debug clean