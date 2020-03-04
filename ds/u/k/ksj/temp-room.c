inherit ROOM;

void create()
{
 set("short","測試房");
 set("long",@LONG
一間蠻寬廣的工作室，四周空盪盪的只有牆壁，牆上與地上則有
許多不同的痕跡，幾條大裂痕剛剛補好，地上只有一個大鐵鉆跟一條
相當粗的黑色鐵鍊。
LONG
    );

        set("light",1);
        set("exits",([
            "south":__DIR__"workroom",
        ]));
/*        set("objects",([
            __DIR__"paper":1,
            __DIR__"blood-scale-surcoat":1,
            __DIR__"crystal-mask":1,
            __DIR__"dark-gloves":1,
            __DIR__"eight-metal-shield":1,
            __DIR__"galaxy-armor":1,
            __DIR__"ice-dragon-pants":1,
            __DIR__"ice-fire-cloth":1,
            __DIR__"ice-iron-neck":1,
            __DIR__"lion-waist":1,
            __DIR__"magnetic-wrists":1,
            __DIR__"nine-gem-crown":1,
            __DIR__"phoenix-boots":1,
            __DIR__"refractile-ring":1,
        ]) );
*/
        setup(); 
}
