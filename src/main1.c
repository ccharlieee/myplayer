/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "start_mplayer.h"
#include "console.h"*/
#include "main1.h"

int song_time=0;
struct lrc{
    int min;
    int second;
    char lr[128];
}song_lrc[128];
char *song_buf[128];
int song_lrc_line = 0;

void print_lrc(void)
{ 
    static int y=4;
    cusor_moveto(30, 6);//光标移到 第4行，第20列
    set_fg_color(COLOR_RED);//设置字体颜色为红色
    if(song_time==((song_lrc[y].min)*60+(song_lrc[y].second)))
    {
        cusor_moveto(30, 6);//光标移到 第4行，第20列
        printf("                                                 ");
        cusor_moveto(30, 6);//光标移到 第4行，第20列
        set_fg_color(COLOR_RED);//设置字体颜色为红色
        printf("%s",song_lrc[y].lr);
         y++;
    }
}
void time(void)
{
    
    cusor_moveto(40, 5);//光标移到 第4行，第20列
    set_fg_color(COLOR_WHITE);//设置字体颜色为红色
    printf("%02d:%02d",song_time/60,song_time%60);
    fflush(stdout);
    sleep(1);
    song_time++;
    return ;   
}

void qiege()
{
    FILE *fp=fopen("../song/人是_.lrc","rb");
  //  FILE *fp=fopen("./好春光.lrc","rb");

    if(fp == NULL)
    {
        perror("fopen");
        return ;
    }
    int i=0;  
    while(1)
    {
        char buf[128]="";
        song_buf[i] = fgets(buf ,sizeof(buf),fp);
        if(song_buf[i] == NULL)
            break;
        if(*song_buf[i] == '[')
        {
            sscanf(song_buf[i],"[%d:%d",&song_lrc[i].min,&song_lrc[i].second);
            song_buf[i] += 10;
            if(*song_buf[i] == ']') song_buf[i]+=2;
            sscanf(song_buf[i],"%s",song_lrc[i].lr);
            
            //printf("%d:%d    %s\n",song_lrc[i].min,song_lrc[i].second,song_lrc[i].lr);
            i++;            
        }
    }
    song_lrc_line =i-1;
    fclose(fp);
}
int main1()
{ 
    memset(song_lrc,0,sizeof(song_lrc));
    qiege();
    mplayer_play("../song/人是_.mp3");
  // mplayer_play("./好春光.mp3");
    
    clear_screen();//清屏幕内容
    cusor_moveto(35, 5);//光标移到 第4行，第20列
    set_fg_color(COLOR_WHITE);//设置字体颜色为红色
    int i;
    for(i=0;i<4;i++)
    {
        cusor_moveto(35, i+1);//光标移到 第4行，第20列
        set_fg_color(COLOR_WHITE);//设置字体颜色为红色
        printf("%s\n",song_lrc[i].lr);
    }
   // printf("%d   %d",song_lrc[song_lrc_line].min,song_lrc[song_lrc_line].second);
    //while(((song_lrc[song_lrc_line].min)*60+song_lrc[song_lrc_line].second) != song_time)
    while(!(song_time/60==song_lrc[song_lrc_line].min && song_time%60 == song_lrc[song_lrc_line].second))
    {
        time();
        print_lrc();       
    }
    printf("\n");
    return 0;  
}


