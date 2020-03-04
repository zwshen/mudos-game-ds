#include <room.h>
inherit ROOM;

void create()
{
 set("short","河堤");
 set("long",@LONG
這裡是一座高高的土堤，土堤上鋪著大小不一的石塊，由於裴伊
川每年都會犯濫，村民為了保護村莊及農田，所以築了這道土堤，但
是河床每年逐漸增高所以雖然土堤年年築高，在河水氾濫時仍會造成
村民不小的損失。
LONG);
   set("exits",([ 
       "south":__DIR__"room31",
       "north":__DIR__"room33",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

void reset()
{
 if( !random(5) )
 {
   set("objects",([
   __DIR__"npc/garatsupa":1,
   ]));
 }
        ::reset();
}
