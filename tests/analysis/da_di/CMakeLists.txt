include(tsar-testing)
tsar_test(TARGET DIDependenceAnalysis TASKS "check;init;fail" TEST check PASSNAME "-da-di")
