#include <stdio.h>
#include <string.h>
int main(int argc,char**argv){ if(argc<2){fprintf(stderr,"Usage: soc <cmd>\n");return 1;} if(!strcmp(argv[1],"whoami")){puts("Biruk-ak <birukaklilu0110@gmail.com>");return 0;} printf("cmd=%s\n",argv[1]); return 0;}
