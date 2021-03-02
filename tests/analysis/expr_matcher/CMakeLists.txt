include(sapfor-testing)
sapfor_add_test(TARGET ClangExprMatcherPass
  TASKS "pass;fail" TEST pass PASSNAME "-clang-expr-matcher")
