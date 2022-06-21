PROGRAM_NAME ?= upc_program
PTHREADS ?= 4
PPROCS ?= 1
COMM_TYPE ?= mpi

NODE_FILE := nodes
INCLUDE_DIR := ./include
SRC := ./src
SRCS := \
	${SRC}/main.c \

CONFIG_DIR := /opt/nfs/config


all: compile run

configure:
	source ${CONFIG_DIR}/source_bupc_2021.4.sh
	${CONFIG_DIR}/station206_name_list.sh 1 16 > ${NODE_FIME}

compile:
	upcc -bupc -network=${COMM_TYPE} -pthreads=${PTHREADS} ${SRCS} -o ${PROGRAM_NAME}

run:
	UPC_NODEFILE=${NODE_FILE} upcrun -shared-heap 256M -c ${PTHREADS} -N ${PPROCS} -n $$(( ${PTHREADS} * $(PPROCS) )) ./${PROGRAM_NAME}

clean:
	rm ${PROGRAM_NAME}

