SRC_DIR:=src
INCLUDE_DIR:=include

DATA_DIR := data
DATA_SRC := $(DATA_DIR)/generated_data.csv
DATA_OUT_FFT := $(DATA_DIR)/fft_data.csv
DATA_OUT_IFFT := $(DATA_DIR)/rev_fft_data.csv

SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/file_utils.c \
	$(SRC_DIR)/fft.c

all: build run

data:
	mkdir -p $(DATA_DIR)
	$(PYTHON) $(SCRIPTS_DIR)/datagen.py &

build:
	upcc -gupc -Wc,"-fPIE" -network=udp ${SRCS} -I ${INCLUDE_DIR} -o program_upc
run: build data
	UPC_NODEFILE=nodes upcrun -shared-heap 256M -c 4 -N 8 -n 32 ./program_upc ${DATA_SRC}

clean:
	rm -f program_upc
