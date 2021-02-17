include(sapfor-testing)
sapfor_add_test(TARGET ClangInline
  TASKS "pass" TEST pass PASSNAME "-clang-inline")
