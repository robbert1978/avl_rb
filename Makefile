build:
	rm -rf bin
	mkdir bin
	clang++ -O3 avl.cpp -o bin/avl
	clang++ -O3 red_black.cpp -o bin/red_black
	clang++ -O3 main.cpp -o bin/main
	clang++ -O3 test_cases/gen_test.cpp -o test_cases/gen_test
gen_test:
	cd test_cases ; \
	./gen_test ; \
	cd ..
run:
	./bin/main
clean:
	rm -rf bin
