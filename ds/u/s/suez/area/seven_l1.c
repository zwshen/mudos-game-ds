
inherit ROOM;

void create()
{
 set("short","草叢");
        set("long",
"讓人分不清方向的雜草叢。\n"
        );

         set("exits", ([
         "east": __DIR__"grass",
         "west":__DIR__"grass",
         "north":__DIR__"grass",
         "south": __DIR__"grass",
         "northwest": __DIR__"grass",
         "northeast": __DIR__"seven_l2",
         "southwest": __DIR__"grass",
         "southeast": __DIR__"grass",
         ]));
         set("item_desc",([
       "石敢當":"上面寫著：「生者不生，死者不死。」\n"
         ]));
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
