file(GLOB_RECURSE test_sources *.cpp)

add_executable(jian-test ${test_sources} ${jnpacks_sources})
target_link_libraries(jian-test ${EXTRA_LIBS})

install(TARGETS jian-test DESTINATION bin)

