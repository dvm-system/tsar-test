include(sapfor-testing)
sapfor_add_test(TARGET ClangPropagate
  TASKS "pass;fail" TEST pass PASSNAME "-clang-propagate")

