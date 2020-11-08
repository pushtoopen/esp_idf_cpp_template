set(SOURCES ./gpio.cpp) #stores gpio.cpp path in SOURCES keyword/variable

#idf_component_register(SRCS ./src/main.cpp #alternate method of referring to sources
idf_component_register(SRCS ${SOURCES}
						INCLUDE_DIRS .
						REQUIRES driver) 
						