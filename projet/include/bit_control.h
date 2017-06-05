#ifndef BIT_CONTROL_H
#define BIT_CONTROL_H
#define set_bit(adresse,bit) ((adresse)|=(0x1<<(bit)))
#define clear_bit(adresse,bit) ((adresse)&=(~(0x1<<(bit))))
#define toggle_bit(adresse,bit) ((adresse)^=(0x1<<(bit)))
#define test_bit(adresse,bit) ((adresse)=((adresse)>>(bit))&1)
#endif
