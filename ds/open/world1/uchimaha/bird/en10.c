#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","東北澤林");

 set("long",@LONG
你現在來到狐狸穴的洞口, 血腥味一陣陣的飄來,
你感覺附近死氣沉沉的, 好像隨時會有可怕的是發生一
樣, 你不禁直冒冷汗, 心中想著到底要不要進去洞裡呢?
你的前方便是狐狸的巢穴了。
 
LONG
    );
 
 set("exits",(["enter":__DIR__"en11",
               "southeast":__DIR__"en9",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
