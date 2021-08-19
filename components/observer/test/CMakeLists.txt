add_executable(Observer_UnitTest "")

target_sources(Observer_UnitTest
    PRIVATE
        ObserverTest.cpp)

target_link_libraries(Observer_UnitTest ${CONAN_LIBS})

add_test(NAME Observer_UnitTest
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND Observer_UnitTest)