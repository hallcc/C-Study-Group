#include <stdio.h>
#include <stdlib.h>

int main()
{
	int primes[99]; //initialize at most 99 spots for prime numbers for interval 3 - 100
	primes[0] = 2; //we know 2 is prime, so populates first instance
	int p = 1; //1 is yes, 0 is no
	int counter = 1; //count start at one since primes[0] is populated
	int i, j; //initialize i for multiple uses
	FILE *fp; //FILE Pointer

	for (i = 3; i < 101; i++) 
	{
		for (j = 0; j < counter; j++)
		{
			if (i % primes[j] == 0)
			{
				p = 0;
			}
		}
		if (p == 1)
		{
			primes[counter] = i;
			counter++;
		}
		p = 1;
	}

	for (i = 0; i < counter; i++) 
	{
		fp = fopen("Primes.txt", "a"); //create file Primes.txt for output, mode "w" for writing to file
		printf("%d\n", primes[i]); //write output to user
		fprintf(fp, "%d\n", primes[i]); //print output to file
		fclose(fp); //close file
	}
}
