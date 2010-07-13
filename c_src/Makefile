uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
OPTIMIZATION?=-O2
ifeq ($(uname_S),Darwin)
  CFLAGS?= -O3 -fPIC -bundle -flat_namespace -undefined suppress -fno-common -Wall -I /usr/local/lib/erlang/usr/include
  CCLINK?=  -L/usr/local/lib/erlang/usr/lib -lerts
else
  CFLAGS = -O3 -fPIC -shared -fno-common -Wall -I /usr/local/lib/erlang/erts-5.8/include/
  CCLINK?= -L/usr/local/lib/erlang/erts-5.8/lib/ -lerts -luuid
endif
CCOPT= $(CFLAGS) $(CCLINK) $(ARCH) $(PROF)
DEBUG?= -g -rdynamic -ggdb 

OBJ = uuid.so

all: uuid.so

uuid.so: uuid.c
	$(CC) -o ../ebin/uuid.so $(CCOPT) uuid.c

clean:
	rm -rf ../ebin/uuid.so








