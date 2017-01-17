file(GLOB_RECURSE test_sources *.cpp)
file(GLOB_RECURSE jian_sources ../jian/*.cpp)

add_executable(jian-test ${test_sources} ${jian_sources} ${jnpacks_sources})
target_link_libraries(jian-test ${EXTRA_LIBS})

install(TARGETS jian-test DESTINATION bin)

