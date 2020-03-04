// Room: /u/l/luky/room/pearl_26.c
inherit ROOM;
void create()
{
set("short", "[1m¹L¹Ò«Ç[m");
set("long", @LONG

                                                  ¢¬
¡Ä¡Ä        ³o¸Ì¬OºÑ¹pº¸¹qÅK¯¸ªº®È      ¡Ä¡Ä¡Ä¡Ä¢¬
" ¢y¢­¡Ä¡Ä«È¹L¹Ò«Ç¡A¬°¤F¦w¥þ¦]¯Àªº¡Ä¡Ä¢¬¢j'    "¢j¢¨
: ¢y¢y    ¦Ò¶q¡A©Ò¦³Æ[¥ú«È³£¥²¶·±µ    ¢j¢j  "  :¢j¢i
= ¢y¢y    ¨üÄY®æªºÀË¬d¡C³\¦hµLªk¤J    ¢j¢j     =¢j¢i
: ¢y¢¬¡Ã¡Ã¹Òªº¤H¥¿¤£Â_¦a©ê«èºÑ¹pº¸¡Ã¡Ã¢­¢j   -==¢j¢i
¡Ã¡Ã      ¦U¶µÄY­Vªº³W©w¡C              ¡Ã¡Ã¡Ã¡Ã¢­¢i
                                                  ¡Ã¢j
                                                    ¢­

LONG
);
set("objects",([
__DIR__"npc/passenger":1,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_27",
"east" : __DIR__"pearl_12",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
