include(sapfor-testing)
sapfor_add_test(TARGET ClangRemoveRedarray
  TASKS "pass" TEST pass PASSNAME "-clang-remove-redarray")