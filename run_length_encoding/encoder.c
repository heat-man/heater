#include <stdio.h>

int encrypt(FILE *input, FILE *output);

int main(int argc, char* argv[])
{
	if(argc < 3){
		printf("usage: encoder.exe [file to encode] [output file]\n");
		return 0;
	}
	FILE *input;
	FILE *output;
	input = fopen(argv[1], "rb");
	output = fopen(argv[2], "wb");
	if(!encrypt(input, output)) return 0;
	puts("Done\n");
	fclose(input);
	fclose(output);
	return 0;
}

int encrypt(FILE *input, FILE *output){
	int nowChar;
	int prevChar;
	int count;
	if(input == NULL || output == NULL){
		return 0;
	}
	
	prevChar = -1;
	count = 0;
	while(1){
		nowChar = fgetc(input);
		if(nowChar == -1)
			break;
		fputc(nowChar, output);
		if(nowChar == prevChar){
			count = 0;
			while(1){
				nowChar = fgetc(input);
				if(nowChar == -1) break;
				if(nowChar != prevChar){
					fputc(count, output);
					fputc(nowChar, output);
					prevChar = nowChar;
					break;
				}
				if(++count == 255)
				{
					fputc(255, output);
					prevChar = -1;
					break;
				}
			}
		} else{
			prevChar = nowChar;
		}
		if(nowChar == -1){
			fputc(count, output);
			break;
		} 
	}
	return 1;
}
		










































	
