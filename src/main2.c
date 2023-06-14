#include "main2.h"

char *song_list[128];

void get_song(void)
{
    int i=0;
    FILE *fp=fopen("../song/song.txt","rb");
    while(1)
    {
        char buf[128]="";
        song_list[i] = fgets(buf ,sizeof(buf),fp);
        if(song_list[i] == NULL)
            break;
        //strncpy(song_list[i],song_list[i],strlen(song_list[i])-4);
       // sscanf(song_list[i],"%s.mp3",song_list[i]);
        printf("%s\n",song_list[i]);
        i++;            
        }
    
}
void main2(void)
{
    char buf[128] = "";
    cusor_moveto(30, 20);//光标移到 第4行，第20列
    printf("i am here \n");

    while(1)
    {
        cusor_moveto(30, 20);//光标移到 第4行，第20列
        memset(buf,0,sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)]=0;
        if(strstr(buf,"list") != 0)
        {
            cusor_moveto(30, 20);//光标移到 第4行，第20列
            set_fg_color(COLOR_YELLOW);//设置字体颜色为红色  
            printf("will list songs\n");
            get_song();
        }
        else if(strstr(buf,"change") != 0)
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
