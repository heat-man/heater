#include <stdio.h>

int encrypt(FILE *in, FILE *out);

int main(int argc, char* argv[])
{
	if(argc < 2){
		printf("usage: encoder.exe [file to encode] [output file]\n");
		return 0;
	}
	FILE *in;
	FILE *out;
	in = fopen(argv[0], "rb");
	out = fopen(argv[1], "wb");
	encrypt(in, out);
	puts("Done\n");
	fclose(in);
	fclose(out);
	return 0;
}

int encrypt(FILE *in, FILE *out){
	int nowChar;
	int prevChar;
	int count;
	if(in == NULL || out == NULL){
		return 0;
	}
	
	prevChar = -1;
	count = 0;
	while(1){
		nowChar = fgetc(in);
		if(nowChar == -1)
			break;
		fputc(nowChar, out);
		if(nowChar == prevChar){
			count = 0;
			while(1){
				nowChar = fgetc(in);
				if(nowChar == -1) break;
				if(nowChar != prevChar){
					fputc(count, out);
					fputc(nowChar, out);
					prevChar = nowChar;
					break;
				}
				if(++count == 255)
				{
					fputc(255, out);
					prevChar = -1;
					break;
				}
			}
		} else{
			prevChar = nowChar;
		}
		if(nowChar == -1){
			fputc(count, out);
			break;
		} 
	}
	return 0;
}
		










































	
