default:
	gcc -Wall -g utils.c tokenizer.c -o tokenizer

clean:
	rm tokenizer

test:
	./tokenizer " " "hello world"
