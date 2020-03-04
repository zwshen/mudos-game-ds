inherit ROOM;

void create()
{
        set( "short", "地底洞穴") ;
        set( "long", @LONG
偌大的通道中，由一塊塊的花崗岩拼湊而成的地板上，光滑且清
潔，但是花崗岩地板的接縫卻傳來陣陣腐臭，目前可以確定的是，通
道的盡頭應該就是這個地底洞穴的真相所在，由這樣規模的人造通道
來看，前方應該有相當巨大的建築。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-46",
                  "south" : __DIR__"room-44",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
