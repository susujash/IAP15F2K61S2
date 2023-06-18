#include "su_digital_tube.h"
#include <reg52.h>
#include "su_common_typedef.h"
#include "su_latch.h"

uint8_t digitaltube_show[8]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};//用于最后显示的数码管缓存数组

uint8_t code t_display[]={                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

uint8_t code T_COM[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //位选

void DigitalTubeDisplay(uint8_t com,uint8_t num)//数码管显示
{
	// 消隐
	Select_Latch(7);P0 = 0xFF; 
	// 送位选
	Select_Latch(6);P0=T_COM[com]; 
	// 送段码
	Select_Latch(7);P0=num; 
}
