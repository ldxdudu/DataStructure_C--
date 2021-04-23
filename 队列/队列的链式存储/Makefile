# 目标：依赖（条件）
# $@表示目标 $^表示所有依赖 $<表示依赖中的第一个
# wildcard 通配符
# patsub 字符串替换
# LDFLAGS 所要链接的库
# 常用变量 #
CPPFLAGS= -Iinclude
CFLAGS= -g -Wall
LDFLAGS= 
CC=g++


src = $(wildcard *.cpp)
obj = $(patsubst %.cpp,%.o,$(src))
target = app

$(target):$(obj)
	$(CC) $^ $(LDFLAGS) -o $@
%.o:%.cpp
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY:clean
# 彻底清除生成的过程文件
clean:
	-rm -f *.o
	-rm -f app
	-rm -f run_*
	-rm -f a.out
