
RACK_DIR ?= ../..


SOURCES = $(wildcard src/*.cpp)







DISTRIBUTABLES += $(wildcard LICENSE*) res
# Must include the VCV plugin Makefile framework
include $(RACK_DIR)/plugin.mk


