#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", HIC"廣寒宮大門"NOR);
        set("long",@LONG

你看了看四周，除了眼前這扇發散著淡淡青色光芒的巨大門扉之外，
是一遍廣闊無邊的荒涼世界，除了砂石之外別無它物。你抬頭望向天
空，咦、、、竟然有一個比平常月亮大了好幾倍的藍色月亮掛在天際
，這到底是怎麼回事呢？抱著滿腹的疑雲向著門扉走去，你才發現到
門扉上方浮刻著--廣寒宮--三個大字，原來這就是武林傳說中的神秘
幫派--月族的根據地。

LONG
        );
        //set("outdoors","land");
        set("light",1);
        set("exits",([
  "north" : __DIR__"room2.c",
]));
        set("item_desc",([
  "門扉": "這扇門散發出淡淡的青色光芒，上面雕了三個古字--廣寒宮。\n",
]));
        set("moon_club_out",1); //月族幫會出口
      set("no_goto",1);
        set("str_room",1); // add by whoami 2006.06.13
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" ) tell_object(me,"你急忙的推開門扉朝裡頭走去。\n");
        return ::valid_leave(me, dir);
}

