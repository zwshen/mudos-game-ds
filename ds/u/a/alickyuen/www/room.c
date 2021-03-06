#include <ansi.h>
#include <room.h>
inherit ROOM;

string *areas = ({
   "/open/world1/acme/area/",
   "/open/world1/tmr/area/",
   "/open/world1/whoami/birdarea/",
   "/open/world1/wu_sha_town/"
});

string pace()
{
   string dir,*file;
   dir = areas[random(sizeof(areas))];
   file = get_dir(dir);
   return dir + file[random(sizeof(file))];
}

void create()
{
   set("short",HIW+BLK"▂▅▆▇█"NOR);
   set("long",
WHT"\n█████"NOR+RED"█████"YEL"█████"BLU"█████\n"
HIW"█████"HIR"█████"HIY"█████"HIB"█████\n"
BLK"█████"HIM"█████"HIG"█████"HIC"█████\n\n"NOR);
   set("no_clean_up",0);
   set("light",1);               
   set("exits", ([
       "west" : __DIR__"workroom",]));
   set("valid_startroom", 1);
   setup();
}

void init()
{
   object me = this_player();

   if(geteuid(me) != "www")
   {
       string pace = pace();

       if(!load_object(pace))
       {
          me->move("/u/w/www/workroom");
          return;
       }
       tell_room(pace,me->name()+"莫名其妙的走到此地。\n");
       message_vision(HIR"\n\n[$N莫名其妙的走到 "NOR+pace->query("short")+HIR"]\n\n"NOR,me);
       me->move(pace);
   }
}
