inherit ROOM;

void create()
{
        set( "short", "地底洞穴") ;
        set( "long", @LONG
整個洞穴被開鑿成四四方方的大房間，四周的石壁上雕刻著許多
壁畫，莊嚴肅穆的氣氛，浩大的工程景象，讓你覺得個人的渺小，差
點跪了下來膜拜。房間的盡頭有一個往下的大樓梯，正在等著你。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-01",
                  "south" : __DIR__"room-45",
        ]));
        set("objects",([
                   __DIR__"../npc/tree_monster" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "壁畫" : "雕刻著八條栩栩如生的火龍的壁畫，並刻有「八歧」兩個大字。\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}
