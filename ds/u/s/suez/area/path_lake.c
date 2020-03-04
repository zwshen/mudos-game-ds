
inherit ROOM;

void create()
{
 set("short","小水漥");
        set("long",@LONG
山泉沿著山溝流到這裡，逡巡徘徊，久而久之便在這裡挖出了一個小
水漥，仔細一看，水漥中還有小魚在游著呢！你不禁又重拾遺忘以久的童
心，拋開武林中的恩恩怨怨，盡情享受這世外桃源的風光。
LONG
        );

         set("exits", ([
         "east": __DIR__"path_t",
         ]));
        set("objects",([
              __DIR__"npc/fong-wu-yen" : 1,
              ]) );
        
        set("outdoors","land");
        
        setup();

        replace_program(ROOM);

 }
