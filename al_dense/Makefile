run:
	gcc scalar_product.c -o scalar_product -g -funroll-loops -O3 -march=native -fno-omit-frame-pointer -mprefer-vector-width=512 -fopenmp

	maqao OV --create-report=one OMP_NUM_THREADS=4 ./scalar_product --include-kernel --sampling-rate=high -xp=maqao-report --replace

clean:
	rm scalar_product