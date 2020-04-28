#!/usr/bin/make -f

.DEFAULT_GOAL:=help
.PHONY: help array clean
.SILENT: help array clean

help:
	$(call msg_info,"Build targets:")
	echo "array       - Build target array"

array:
	${MAKE} -C array

clean:
	${MAKE} -C array clean

