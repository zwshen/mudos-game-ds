
inherit ROOM;

void create()
{
 set("short","山中小徑");
        set("long",@LONG
幾隻雀兒停在你身旁好奇的看著你，但你想接近時又飛入林中，你正
走在一條幽靜小道上。
LONG
        );

         set("exits", ([
         "southwest": __DIR__"path_1",
         "northup": __DIR__"path_t",
         ]));

        set("outdoors","land");
        
        setup();
        replace_program(ROOM);

 }