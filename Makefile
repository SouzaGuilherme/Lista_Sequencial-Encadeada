encadeada:
	gcc -std=c11 -O0 -Wall listaEncadeada.c test.c -o main
	./main

sequencial:
	gcc -std=c11 -O0 -Wall listaSequencial.c test.c -o main
	./main

clean:
	rm main
