include(sapfor-testing)
sapfor_add_test(TARGET ClangDVMHParallel
  TASKS "pass;serial" TEST pass PASSNAME "-clang-experimental-apc-dvmh")
