obj-m = kobject_test.o

UNAMER = $(shell uname -r)

all:
	make -C /lib/modules/$(UNAMER)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(UNAMER)/build M=$(PWD) clean
