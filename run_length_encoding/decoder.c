#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("usage: decoder.exe [file to decode] [output file]\n");
		return 0;
	}
	FILE *in;
	FILE *out;
	char file_in[100], file_out[100], _count;
	int nowChar, prevChar, count;
	scanf("%s", file_in);
	scanf("%s", file_out);
	in = fopen(file_in, "rb");
	out = fopen(file_out, "wb");
	prevChar = -1;
	while(1){
		nowChar = fgetc(in);
		if(nowChar == -1) break;
		fputc(nowChar, out);
		if(nowChar == prevChar){
			_count = fgetc(in);
			if(_count == -1) break;
			count = _count - '0';
			for(int i=0; i<count; i++) fputc(nowChar, out);
		}
		prevChar = nowChar;
	}
	fclose(in);
	fclose(out);
	return 0;
}		
	
