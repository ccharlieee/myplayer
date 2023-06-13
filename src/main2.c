#include "main2.h"

void main2(void)
{
    char buf[128];
    cusor_moveto(30, 20);//光标移到 第4行，第20列
    printf("i am here \n");

    while(1)
    {
        cusor_moveto(30, 20);//光标移到 第4行，第20列
        memset(buf,0,sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)]='\0';
        if(strcmp(buf,"list") == 0)
        {
            cusor_moveto(30, 20);//光标移到 第4行，第20列
            set_fg_color(COLOR_YELLOW);//设置字体颜色为红色  
            printf("will list songs\n");
            
            

        }
        else if(strcmp(buf,"change") == 0)
        {
            cusor_moveto(30, 20);//光标移到 第4行，第20列
            set_fg_color(COLOR_YELLOW);//设置字体颜色为红色  
            printf("will change mode\n");
        }
        else
        {
            printf("%s\n",buf);
        }
    }

}
