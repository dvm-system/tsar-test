add_subdirectory(de_decls)
add_subdirectory(dvmh_sm)
add_subdirectory(inline)
add_subdirectory(openmp)
add_subdirectory(propagate)
add_subdirectory(replace)

if (TSAR_ENABLE_FORTRAN)
  add_subdirectory(replace_const)
endif()

