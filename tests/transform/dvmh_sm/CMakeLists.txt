include(sapfor-testing)
sapfor_add_test(TARGET ClangDVMHSMParallel
  TASKS "pass;serial" TEST pass PASSNAME "-clang-dvmh-sm-parallel")

