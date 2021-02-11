void bar(double (*Y)[10]);

void foo(double X) {
#pragma spf metadata replace(bar(X))
}

