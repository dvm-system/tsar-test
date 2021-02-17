include(sapfor-testing)
sapfor_add_test(TARGET ClangOMPParallel
  TASKS "pass" TEST pass PASSNAME "-clang-openmp-parallel")
