#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("臨時置物箱",({"box"}));
        set("unit", "個");
        set("long",@LONG
        
  一個破舊的箱子。上面還畫了一隻大龍蝦的圖案。你可以把一些雜
物放在裡面或是從裡面拿東西出來。

  放東西: put [東西] in box
  拿東西: get [東西] from box

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
      set_max_capacity(400); //2003.4.16  10000 -> 400  by ksj
        setup();
}

