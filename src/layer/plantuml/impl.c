init(){
	/*nothing to do*/
}

read(void *fn){
	void *f = open(fn);
	uint16_t len = len(f);

	alloc(b, len);

	free(b);
	close(f);
}
