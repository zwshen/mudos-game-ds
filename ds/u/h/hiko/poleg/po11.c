inherit ROOM;
void create()
{
        set("short", "泊浪村內側");        
        set("long",@LONG
這裡是泊浪村廣場北側，由於屬於內側看起來人較少，在你的東邊
有著一間住宅，感覺十分樸素卻風格特殊，是用磚砌的，在這個大部分
人們皆用茅木製屋時，卻有這種形式建築，想必地位該是蠻高的，聽說
漁會頭目就住這附近。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po12",  
  "east" : __DIR__"po11e",
  "south" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}







