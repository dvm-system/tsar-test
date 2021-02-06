function(tsar_test)
  # Syntax:
  # tsar_test TARGET cmake-target-name
  #
  # Generates custom commands for invoking pts.pl.
  # Corresponding targets Test${TARGET}, Init${TARGET}, Fail${TARGET}, Clean${TARGET} are generated.
  #
  # If ${PTS_EXECUTABLE} PTS executable does not exist do nothing.

  cmake_parse_arguments(TT "" "TARGET;PLUGIN;PASSNAME" "" ${ARGN})

  if(NOT TT_TARGET)
    message(FATAL_ERROR "TARGET name required by tsar_testing")
  endif()
  set(TT_TEST_TARGET Test${TT_TARGET})
  set(TT_INIT_TARGET Init${TT_TARGET})
  set(TT_FAIL_TARGET Fail${TT_TARGET})
  set(TT_CLEAN_TARGET Clean${TT_TARGET})

  if(NOT PERL_FOUND OR NOT EXISTS "${PTS_EXECUTABLE}")
    return()
  endif()

  if(NOT TT_PASSNAME)
    set(TT_MESSAGE "Testing...")
    set(TT_INIT_MESSAGE "Initialization of tests...")
    set(TT_FAIL_MESSAGE "Running of skipped tests...")
    set(TT_CLEAN_MESSAGE "Cleaning of test results...")
  else()
    set(TT_MESSAGE "Testing '${TT_PASSNAME}' pass...")
    set(TT_INIT_MESSAGE "Initialization of tests for '${TT_PASSNAME}' pass...")
    set(TT_FAIL_MESSAGE "Running of skipped tests for ${TT_PASSNAME}' pass...")
    set(TT_CLEAN_MESSAGE "Cleaning of test results for ${TT_PASSNAME}' pass...")
  endif()

  add_custom_target(${TT_TEST_TARGET}
    COMMAND ${PROJECT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE} ./check
    COMMENT ${TT_MESSAGE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  set_target_properties(${TT_TEST_TARGET} PROPERTIES FOLDER "${TSAR_TEST_FOLDER}")
  set_target_properties(${TT_TEST_TARGET} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
  set_property(GLOBAL APPEND PROPERTY TSAR_TEST_TARGETS ${TT_TEST_TARGET})

  add_custom_target(${TT_INIT_TARGET}
    COMMAND ${PROJECT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE} ./init
    COMMENT ${TT_INIT_MESSAGE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  set_target_properties(${TT_INIT_TARGET} PROPERTIES FOLDER "${TSAR_TEST_FOLDER}")
  set_target_properties(${TT_INIT_TARGET} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
  set_property(GLOBAL APPEND PROPERTY TSAR_TEST_INIT_TARGETS ${TT_INIT_TARGET})

  add_custom_target(${TT_FAIL_TARGET}
    COMMAND ${PROJECT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE} ./fail
    COMMENT ${TT_FAIL_MESSAGE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  set_target_properties(${TT_FAIL_TARGET} PROPERTIES FOLDER "${TSAR_TEST_FOLDER}")
  set_target_properties(${TT_FAIL_TARGET} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
  set_property(GLOBAL APPEND PROPERTY TSAR_TEST_FAIL_TARGETS ${TT_FAIL_TARGET})

  add_custom_target(${TT_CLEAN_TARGET}
    COMMAND ${PROJECT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE} clean ./init ./check ./fail
    COMMENT ${TT_CLEAN_MESSAGE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  set_target_properties(${TT_CLEAN_TARGET} PROPERTIES FOLDER "${TSAR_TEST_FOLDER}")
  set_target_properties(${TT_CLEAN_TARGET} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
  set_property(GLOBAL APPEND PROPERTY TSAR_TEST_CLEAN_TARGETS ${TT_CLEAN_TARGET})

  include(CTest)

  add_test(NAME ${TT_TARGET}
    COMMAND ${PROJECT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE} ./check
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endfunction(tsar_test)
