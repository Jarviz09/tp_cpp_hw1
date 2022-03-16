add_test( TestOpenedFile.isOpened /home/zaynutdin/CLionProjects/tp_cpp_hw1/cmake-build-debug/tests/my_first_test [==[--gtest_filter=TestOpenedFile.isOpened]==] --gtest_also_run_disabled_tests)
set_tests_properties( TestOpenedFile.isOpened PROPERTIES WORKING_DIRECTORY /home/zaynutdin/CLionProjects/tp_cpp_hw1/cmake-build-debug/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( my_first_test_TESTS TestOpenedFile.isOpened)
