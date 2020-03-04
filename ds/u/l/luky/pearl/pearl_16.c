// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"¬Ã¯]¥_µó"NOR);
set("long", @LONG

  §A¥¿¦ì©óºÑ¹pº¸Âíªº¬Ã¯]¥_µó¡C¥_¤è¬O¥»Âí¥D­nªº°Ó©±¡A¦pªG§A©|
¦³¦h¾lªº¸Ë[1;33m ¢x       ¢d¢e¢f¢g¢g¢g¢f¢e¢d             ¢x[m ³Æ¡A¤£
§«¨Ó¦¹¤¤[1;33m   ¡¶¢d¢e¢f[m¢x¢¨¢©¢x¢¨¢©¢x¢¨¢©¢x[1;33m¢f¢e¢e¢d¢d¢c¡¶[m¤ß»P¨ä
¥L«_ÀIªÌ ¢y ¢x ¥Ð¥Ð¢x¥Ð¥Ð¢x¥Ð¥Ð¢x¥Ð¥Ð¢x ¥Ð ¥Ð ¢x¥Ð ¢j¢k ¥æ´«
         ¢y ¢x[33m¡Ä¢c¢d¢e¢e¢f¢f¢f¢f¢f¢e¢e¢d¢c¡Ä[m  ¢x   ¢j¢k
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã :¢­  ¢¨¢© ¢¨¢© ¢¨¢©  ¢¬: ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã
:      -         :¢y  ¡_  ùúùùùû  ¡_  ¢j:[1;35m¡i·Rº¸¸Ë³Æ¤¤¤ß¡j[m  :
= ."   -       - :¢y  ¡ò[1;34m   ¢i¢i[m   ¡ò  ¢j:                  =
==-  " -       - :¢y[34m       ¢i¢i[m       ¢j:  -       - .   -==
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã  ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã

LONG
);
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_29",
"west" : __DIR__"pearl_15",
"east" : __DIR__"pearl_17",
]));
set("no_clean_up", 0);
set("light",1);
setup();
load_object(__DIR__"npc/item/greentea");
}
