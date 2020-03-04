// Room: /u/l/luky/room/pearl_13.c
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIG"¬Ã¯]¦èµó"NOR);
set("long", @LONG

[31m                             ¢©[m
ùþ¢­                    [1;33m¢¨[43mùùùùùù[1;40;33m¢©[m                     ¢¬ùþ
ùþ :¢­    ³o¸Ì¬O¬Ã¯]¦èµó¡C³o±øµó¦V«n¥_©µ¦ù¡A¥Ñ©ó³o   ¢¬: ùþ
ùþ : :¢j¸Ìªº³òÀð§¡¬O¥Ñµo¥úªº¬Ã¯]©Ò«Øºc¦Ó¦¨ªº¡A©Ò¥H ¢y: : ùþ
ùþ : :¢j§Y¨Ï¬O¦b®ü©³¤]¯à²M·¡ªº¬Ý¨£¤è¦V¡C§A¬Ý¨£¥_¤è ¢y: : ùþ
ùþ :¢¬  »·³B¦³­Ó¤j«Ø¿vª«¡A§Ù³Æ¦ü¥G¤Q¤À´ËÄY¡C         ¢­: ùþ
ùþ¢¬                                                   ¢­ùþ


LONG
	);
set("objects",([
__DIR__"npc/oceaner":1,
__DIR__"npc/oceaner":1,
]));
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_14",
"south" : __DIR__"pearl_12",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
