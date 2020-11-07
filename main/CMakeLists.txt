set(SOURCES ./src/main.cpp) #stores main.cpp path in SOURCES keyword/variable

#idf_component_register(SRCS ./src/main.cpp #alternate method of referring to sources
idf_component_register(SRCS ${SOURCES}
						INCLUDE_DIRS . include
						REQUIRES freertos esp_common) 