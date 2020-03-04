#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"山洞內"NOR);

 set("long",@LONG
這裡的光線相當微弱, 地面也沒有洞口那般乾燥, 濕漉漉的, 你的
頭頂上還不時有水滴滴下來, 石壁上長滿了青苔, 一陣陣霉味夾雜著腐
臭味自更深處傳來, 石頂上蜘蛛網是一張又一張, 跟這裡比起來, 洞口
的黑暗又算不了什麼了, 一隻隻的老鼠在地上驚慌失措的跑來跑去, 他
們似乎沒看過比你更高大的東西了... 
LONG
    );
 set("exits",([ "west":__DIR__"birdpill4_1",
                "east":__DIR__"birdpill3",
    ]));
 set("objects", ([__DIR__"npc/rat" : 6,
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

