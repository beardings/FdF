cmake_minimum_required(VERSION 3.8)
project(FdF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES src/main.c src/ft_itoa_hex.c src/init_struct.c)

add_executable(FdF ${SOURCE_FILES})

target_link_libraries(FdF ${CMAKE_SOURCE_DIR}/libft/libft.a)