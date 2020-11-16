progress:	progress.c
	mkdir -p build
	gcc progress.c -o build/progress -Wall
	
clean:
	rm -f progress
