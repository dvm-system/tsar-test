int foo(){
	return 25;
}

int main(){
	int x;

#pragma spf transform inline
	x = (2 > 3)?0:foo();


	return 0;
}
