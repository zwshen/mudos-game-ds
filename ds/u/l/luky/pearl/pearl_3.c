// Room: /u/l/luky/room/pearl_3.c
inherit ROOM;
void create()
{
set("short","[1;32m¬Ã¯]µó[m");
set("long", @LONG

ùþ¢­                                                   ¢¬ùþ
ùþ :¢­    ²ßºD¤F¬Ã¯]Àð´²µo¥Xªº¥ú¨~«á¡A§Aº¥º¥¯à°÷¬Ý   ¢¬: ùþ
ùþ : :¢j²M·¡«e¤èªº«Ø¿vª«¡Cµµ¦âªº®ü¯ó§Gº¡¤F¹D¸ôªº¨â ¢y: : ùþ
ùþ : :¢j®Ç¡A¤@°¦¤Q¤À¥i·Rªº¤p±H©~ÃÉ±q§A¸}¤U½w½wª¦¹L ¢y: : ùþ
ùþ :¢¬  ¡C¹D¸ô¦V«n¥_¤@ª½©µ¦ù¦Ó¥h¡C                   ¢­: ùþ
ùþ¢¬                                                   ¢­ùþ

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pearl_4",
  "north" : __DIR__"pearl_2",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
