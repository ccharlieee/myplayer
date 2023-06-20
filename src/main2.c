#include "main2.h"

extern int main1(char* buf);
struct song{
    char *song_list;
    int len;
} song_info[128];


void get_song(void)
{

    int i=0;
    FILE *fp=fopen("../song/song.txt","rb");
    
    
    while(1)
    {
        char buf[128]="";
        song_info[i].song_list = fgets(buf ,sizeof(buf),fp);
        strcpy(song_info[i].song_list,buf);

        if(song_info[i].song_list == NULL)
            break;
        //printf("info1 song =%s\n",song_info[i].song_list);
        song_info[i].song_list[strlen(song_info[i].song_list)-5] = 0;
        song_info[i].len = i;
       printf("[%d] %s\n",song_info[i].len,song_info[i].song_list);
             
            //  printf("info1 song =%s\n",song_info[0].song_list);
        i++; 
        }
        printf("info0 song =%s  \n",song_info[0].song_list);
        printf("info1 song =%s  \n",song_info[1].song_list);
}

void list_song(void)
{
    int i = 0;
    while(1)
    {
        if(song_info[i].song_list == NULL)
            break;

        printf("[%d] %s\n",song_info[i].len,song_info[i].song_list);
        i++; 

    }
}
void main2(void)
{
    char buf[128] = "";
    //get_song();
  
    while(1)
    {
        cusor_moveto(30, 20);//光标移到 第4行，第20列
        memset(buf,0,sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)]=0;
        if(strstr(buf,"list") != 0)
        {
            cusor_moveto(0, 15);//光标移到 第4行，第20列
            set_fg_color(COLOR_YELLOW);//设置字体颜色为红色  
            get_song();
          //  printf("info1 song =%s\n",song_info[0].song_list);
            int num = 0;
            scanf("%d",&num);
        
            
            int history = open("../song/history.txt",O_RDWR|O_APPEND);
            if(history < 0)
            {
                perror("open history");
            }
           // write(history,song_info[atoi(buf)].song_list,strlen(song_info[atoi(buf)].song_list));
           main1(song_info[num].song_list);
           printf("%s\n",song_info[num].song_list);
           //char *test = "hahahah";
           write(history,song_info[num].song_list,sizeof(song_info[num].song_list));
            close(history);
        }
        else if(strstr(buf,"change") != 0)
        {
            cusor_moveto(30, 18);//光标移到 第4行，第20列
            set_fg_color(COLOR_YELLOW);//设置字体颜色为红色  
            printf("will change mode\n");
        }
        else
        {
            printf("%s\n",buf);
        }
    }

}
