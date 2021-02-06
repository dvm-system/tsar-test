cmake_minimum_required(VERSION 3.4.3)

project(TSAR_TEST VERSION 0.0.1 LANGUAGES C CXX)

set(TSAR_TEST_DESCRIPTION "Test set for TSAR")
set(TSAR_TEST_HOMEPAGE_URL "https://github.com/dvm-system/tsar-test")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sys/cmake)

set (TSAR_TEST_FOLDER "Tsar testing" CACHE STRING "Specify IDE folder for TSAR tests.")
set (TSAR_TEST_TOOLS_FOLDER "Tools" CACHE STRING "Specify IDE folder for testing utils.")
if (TSAR_TEST_FOLDER)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

find_package(Perl)
if (NOT PERL_FOUND)
  message(SEND_ERROR "Could NOT find Perl which is required to run tests. ")
else()
  message(STATUS "Perl version: ${PERL_VERSION_STRING}")
endif()

set(PTS_EXECUTABLE "" CACHE FILEPATH  "Path to PTS which runs tests.")
if (NOT EXISTS "${PTS_EXECUTABLE}")
  message(SEND_ERROR "Could NOT find PTS which is required to run tests. ")
endif()

set(DVM_PATH "" CACH PATH "Path to DVM System")
if (EXISTS "${DVM_PATH}")
  get_filename_component(DVM_SCRIPT_PATH "${DVM_PATH}/user/dvm" ABSOLUTE)
endif()

if (NOT EXISTS "${DVM_SCRIPT_PATH}")
  message(WARNING "Could NOT find DVM executable which is required to run tests. "
                  "Set DVM_PATH option to run DVMH-based tests.")
endif()

set(OPTION_LIST "--total-time --failed f -s" CACHE STRING "Default PTS options.")
get_filename_component(PTS_PLUGIN_PATH sys ABSOLUTE)
get_filename_component(PTS_TASK_PATH sys ABSOLUTE)

set(EXECUTABLE_NAME "sapfor-test")

if (WIN32)
  set(EXECUTABLE_FILE "${EXECUTABLE_NAME}.bat")
  set(EXECUTABLE_TEMPLATE_NAME "${EXECUTABLE_NAME}.win.in")
else()
  set(EXECUTABLE_FILE "${EXECUTABLE_NAME}")
  set(EXECUTABLE_TEMPLATE_NAME "${EXECUTABLE_NAME}.uni.in")
endif()

# Substitute all @VAR@ variables except generator expressions.
# Change permissions to allow execute the configured file.
configure_file(bin/${EXECUTABLE_TEMPLATE_NAME} tmp/${EXECUTABLE_TEMPLATE_NAME} @ONLY)
file(COPY ${CMAKE_CURRENT_BINARY_DIR}/tmp/${EXECUTABLE_TEMPLATE_NAME}
  DESTINATION bin FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ)
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/tmp)

# Substitute generator expressions.
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE}"
              INPUT "${CMAKE_CURRENT_BINARY_DIR}/bin/${EXECUTABLE_TEMPLATE_NAME}")

# Add target to copy main script to the original 'bin' directory according to current configuration.
add_custom_target(${EXECUTABLE_NAME} ALL
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE}"
                                   "${CMAKE_CURRENT_SOURCE_DIR}/bin/${EXECUTABLE_FILE}"
  COMMENT "Build ${CMAKE_CURRENT_SOURCE_DIR}/bin/${EXECUTABLE_FILE}...")
set_target_properties(${EXECUTABLE_NAME} PROPERTIES FOLDER "${TSAR_TEST_TOOLS_FOLDER}")

install(PROGRAMS "${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/${EXECUTABLE_FILE}" DESTINATION bin)

enable_testing()

add_subdirectory(tests)
