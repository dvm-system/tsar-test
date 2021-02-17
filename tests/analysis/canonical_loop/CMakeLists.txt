include(sapfor-testing)
sapfor_add_test(TARGET ClangCanonicalLoop
  TASKS "pass;fail" TEST pass PASSNAME "-clang-canonical-loop")
