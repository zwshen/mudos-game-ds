#include <room.h>
inherit ROOM;

void create()
{
  set("short","出雲後山");
  set("long",@LONG
這裡是出雲山的後山，四處岩石嶙嶇，佈滿斑斑白雪，強勁的冷
風挾帶雪花旋繞在岩石之間，你注意到有部份的岩壁好像被什麼東西
磨過似的，顯得比較光滑，地面上有些像是被撞碎的大岩塊。
LONG);
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  set("objects",([
      __DIR__"npc/orochi-body":1,
     ]) );
  setup();
}            
