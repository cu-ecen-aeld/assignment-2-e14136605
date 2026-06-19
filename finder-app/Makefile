# 設定編譯器。如果有指定 CROSS_COMPILE 變數，就會加上字首；沒指定就是預設的原生 gcc
CC = $(CROSS_COMPILE)gcc

# 設定編譯時的嚴格檢查條件 (作業要求的常見好習慣)
CFLAGS = -g -Wall -Werror

# 預設執行的目標
all: writer

# 如何把 writer.c 編譯成 writer 執行檔
writer: writer.c
	$(CC) $(CFLAGS) -o writer writer.c

# 清除所有編譯產生出來的檔案
clean:
	rm -f writer *.o
