inherit ROOM;
void create()
{
     set("short","『超•試煉之場』");
      set("long",@LONG
前面有一個巨大的樓梯，從上面隱隱散發的一股無比的戰氣，令人不
吝而寒！旁邊有一名巨大的漢子，脖子上掛著一面金牌，從他的身上隱約
散發出一百年前武林高人—游機子的的氣息。
LONG);
set("exits",([
       "south":__DIR__"9.c",
        "up":__DIR__"14.c",
]) );
set("objects",([
__DIR__"npc/lv1_king"    :1
]));
        set("world", "future"); 
setup();
}
