#include <room.h>
inherit ROOM;

void create()
{
  set("short","鬼之森");
  set("long",@LONG
這裡是陰森詭異的森林，由於鬼怪的棲息使得陰氣凝重，長年濃
霧聚集不散，走在這邊感覺陰陰涼涼的，不時有奇怪的叫聲從森林中
傳來，高度的濕氣使得四周充滿一股腐臭的味道。
LONG);
  set("exits",([ 
      "east":__DIR__"room43",
      "west":__DIR__"room41",
      "south":__DIR__"room38",
      "north":__DIR__"room47",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/human-face-bogle":1,
     ]) );
  setup();
}            
