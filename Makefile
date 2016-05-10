CC=gcc
HSAKMT_INC_DIR=/opt/rocm/libhsakmt/include/libhsakmt
HSAKMT_LIB_DIR=/opt/rocm/lib
HSAKMT_LIB=hsakmt

all: ex01 ex02 ex03 ex04

ex01:
	gcc -I$(HSAKMT_INC_DIR) ex01.c -L$(HSAKMT_LIB_DIR) -l$(HSAKMT_LIB) -o ex01
ex02:
	gcc -I$(HSAKMT_INC_DIR) ex02.c -L$(HSAKMT_LIB_DIR) -l$(HSAKMT_LIB) -o ex02
ex03:
	gcc -I$(HSAKMT_INC_DIR) ex03.c -L$(HSAKMT_LIB_DIR) -l$(HSAKMT_LIB) -o ex03
ex04:
	gcc -I$(HSAKMT_INC_DIR) ex04.c -L$(HSAKMT_LIB_DIR) -l$(HSAKMT_LIB) -o ex04

clean:
	rm ex01 ex02 ex03 ex04

run:
	./ex01
	echo ""
	./ex02
	echo ""
	./ex03
	echo ""
	./ex04
