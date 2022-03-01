#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("usage: decoder.exe [file to decode] [output file]\n");
		return 0;
	}
	FILE *input;
	FILE *output;
	char _count;
	int nowChar, prevChar, count;
	input = fopen(argv[0], "rb");
	output = fopen(argv[1], "wb");
	prevChar = -1;
	while(1){
		nowChar = fgetc(input);
		if(nowChar == -1) break;
		fputc(nowChar, output);
		if(nowChar == prevChar){
			_count = fgetc(input);
			if(_count == -1) break;
			count = _count - '0';
			for(int i=0; i<count; i++) fputc(nowChar, output);
		}
		prevChar = nowChar;
	}
	fclose(input);
	fclose(output);
	return 0;
}		
	
