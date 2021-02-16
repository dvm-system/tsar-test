function(tsar_test)
  # Syntax:
  # tsar_test TARGET cmake-target-name TASKS task-set-list [TEST task] [PASSNAME pass-name]
  #
  # Example:
  # tsar_test(TARGET example TASKS "check;init;fail" TEST check)
  #
  # Generates custom commands for invoking pts.pl.
  # Corresponding targets to run each task from TASKS (${TARGET_PREFXI}${TARGET}) are generated.
  # Each task implies some target prefix.
  # Target to clean the lasts execution results are also generated.
  #
  # Use CTest to generate test for TEST task, which must be presented in TASKS list.
  #
  # If ${TS_PTS_PATH} PTS executable does not exist do nothing.

  cmake_parse_arguments(TS "" "TARGET;TEST;PASSNAME" "TASKS" ${ARGN})

  if(NOT TS_TARGET)
    message(FATAL_ERROR "TARGET name required by tsar_testing")
  endif()
  if(NOT TS_TASKS)
    message(FATAL_ERROR "TASKS set required by tsar_testing")
  endif()

  if(NOT PERL_FOUND OR NOT EXISTS "${TS_PTS_PATH}")
    return()
  endif()

  set(PLUGIN_LIST -I ${PROJECT_SOURCE_DIR}/sys)
  set(TASK_CONFIG -T ${PROJECT_SOURCE_DIR}/sys/tasks)
  set(TASK_TO_CLEAN)

  include(CTest)

  foreach(T ${TS_TASKS})
    string(SUBSTRING ${T} 0 1 FIRST_LETTER)
    string(TOUPPER ${FIRST_LETTER} FIRST_LETTER)
    string(REGEX REPLACE "^.(.*)" "${FIRST_LETTER}\\1" TARGET_PREFIX ${T})

    set(TARGET_NAME ${TARGET_PREFIX}${TS_TARGET})

    add_custom_target(${TARGET_NAME}
      COMMAND ${PERL_EXECUTABLE} ${TS_PTS_PATH} ${TS_PTS_OPTIONS} ${PLUGIN_LIST} ${TASK_CONFIG} "./${T}"
      COMMENT "Run task set '${T}' for '${TS_PASSNAME}' pass..."
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "${TS_TEST_FOLDER}/${TARGET_PREFIX}")
    set_target_properties(${TARGET_NAME} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
    set_property(GLOBAL APPEND PROPERTY TS_TARGETS ${TARGET_NAME})

    if (TS_TEST AND ${T} STREQUAL "${TS_TEST}")
      add_test(NAME ${TARGET_NAME}
        COMMAND ${PERL_EXECUTABLE} ${TS_PTS_PATH} ${TS_PTS_OPTIONS} ${PLUGIN_LIST} ${TASK_CONFIG} "./${T}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      )
    endif()

    set(TASK_TO_CLEAN "${TASK_TO_CLEAN} \"./${T}\"")
  endforeach()

  add_custom_target(Clean${TS_TARGET}
    COMMAND ${PERL_EXECUTABLE} ${TS_PTS_PATH} ${TS_PTS_OPTIONS} ${PLUGIN_LIST} ${TASK_CONFIG} clean ${TASK_TO_CLEAN}
    COMMENT "Clean task sets '${TS_TASKS}' for '${TS_PASSNAME}' pass..."
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  set_target_properties(Clean${TS_TARGET} PROPERTIES FOLDER "${TS_TEST_FOLDER}/Clean")
  set_target_properties(Clean${TS_TARGET} PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD ON)
  set_property(GLOBAL APPEND PROPERTY TS_TARGETS Clean${TS_TARGET})
endfunction(tsar_test)
