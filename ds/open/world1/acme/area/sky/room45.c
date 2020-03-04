// Room45.c

inherit ROOM;

void create()
{
        set("short","天地會中庭");
        set("long", @LONG
你正站在天地會的中庭，這中庭佔有極大的空間。而在你身旁，
正站著二十名幫眾分為兩邊排開。放眼望去遠處，四周松柏合抱，在
壯麗山色下令你心神大振。往北可以到達天地會大殿，往南可以到達
天地會牌坊。

LONG
        );
        set("exits", ([
                "north": __DIR__"room35",
                "south": __DIR__"room55",
        ]));  
        set("objects",([
        __DIR__"item/sky-ming_tree" :1,
]));
        set("light",1);
set("no_goto",1);
        setup();
        set("stroom",1);

}
