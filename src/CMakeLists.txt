
file(GLOB SORT_SRC
	"sort/*.cpp"
	"draw/*cpp"
	"collection/*.cpp")

set(SORT_MAIN "main.cpp")

add_library(${LIB_NAME} ${SORT_SRC})


add_executable(${PROGRAMM_NAME} ${SORT_MAIN})
target_link_libraries(${PROGRAMM_NAME} ${LIB_NAME} ${SFML_LIBRARIES})
