#define set_bit(adresse,bit) ((adresse)|(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^(0x1<<(bit)))
#define test_bit(adresse,bit) (((adresse)>>(bit))&1)

#include <stdio.h>


int main(void){
	printf("set    3rd bit of 0x0FF0 : %x\n",set_bit(0x0FF0,3));
	printf("clear  8th bit of 0x0FF0 : %x\n",clear_bit(0x0FF0,8));
	printf("toggle 8th bit of 0x0FF0 : %x\n",toggle_bit(0x0FF0,8));
	printf("toggle 3rd bit of 0x0FF0 : %x\n",toggle_bit(0x0FF0,3));
	return 0;
}
