if(${BUILD_TESTS}) 
    include(FetchContent)

    FetchContent_Declare(
      googletest
      GIT_REPOSITORY    https://github.com/google/googletest.git
      GIT_TAG           release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
    enable_testing()
    
    set(TEST_BASE_DIR tests)
    set(TESTING_SOURCES
        ${TEST_BASE_DIR}/testTimeArithmatics.cpp
    )
    add_executable(tests ${TESTING_SOURCES})
    target_link_libraries(tests PRIVATE
        datetimecpp
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(tests)
endif()
