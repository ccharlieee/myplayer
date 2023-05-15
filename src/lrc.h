#ifndef __LRC_H__
#define __LRC_H__

int song_time=0;
struct lrc{
    int min;
    int second;
    char lr[128];
};
char *song_buf[128];
extern void time(void);
extern void qiege(void);

#endif 