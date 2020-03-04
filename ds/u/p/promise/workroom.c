#include <room.h>
#include <ansi.h>
inherit ROOM;
void create() 
{ 
                set("short", HIG"©Ð¤l©M«B"NOR);
                set("long", HIC"
¡E¢X¡ï ¡¸¢X ¡O¡E¢X¡ï¢X¡¸¡O?£j¡O¡E¢X¡E¢X¡ï¢X¡ï ¡¸¢X ¡O¡E¢X¡ï¢X¡¸¡O¢X¡O¡E¢X¡ï 
¡E¢X¡ï¢X¡O¡¸¢X¡D¡O¡E¢X¡ï¢X¡O¢X¡D¡O¡E¢X¡ï¢X  ¡O¡O¡E¢X¡ï¢X¡O¡¸¢X¡D¡O¡E¢X¡ï¢X¡E

           ¡@¡@¡ï   ¡@¡@¡@¡@¡ï¡@¢¬
             ¢¬¡@¡@¡@¡@¡@¡@¡@ ¢¬¡@¡@¡ï¡@¡@¡¸¡@¡ï¢¬
         ¡@¢¬¡@¡ï  ___¡ä_  ¡¸¡ï¡@¢¬¡@¡@¡@¡ï¡@¡¸
         ¡¸¡@¡@  _/\\     \\¡@ ¡¸¡@¡ï¡@¢¬
¡@¡@¡@          /\\ _\\\\____\\¡@¡ï¡@¡¸
         ¡@¡@   ||''||''''|
           ~~~~~```````````~~~~~   ¡ñ home¡ñ  
"NOR

);

  set("exits", ([ /* sizeof() == 2 */
  "js" : "/u/j/jangshow/workroom",
  "west" : "/u/p/promise/jailroom", 
  "enter" : "/u/p/promise/testroom",
  "down" : "/d/wiz/hall1",
])); 
        set("objects", ([ /* sizeof() == 1 */

//  __DIR__"npc/eq-man":1, 

]));
                     set("light",1);   
                setup();
                replace_program(ROOM); 
     call_other("/obj/board/promise_b", "???");
}


