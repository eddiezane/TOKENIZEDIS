default:
	gcc -Wall -g -Werror utils.c tokenizer.c -o tokenizer

clean:
	rm tokenizer
