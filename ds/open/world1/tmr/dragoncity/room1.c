inherit ROOM;
void create()
{
  set ("short", "工地");
  set ("long", @LONG

這裡有一些無所是事的工人，或是哈草，或是喝酒
，或是聊天，一些鑽子推車之類的東西散落一地，
看來這裡還要等一些時候才能建好。

你看到一個一臉賊樣的人坐在一旁的休息區，手上
還拿著一張藍圖，不時的低頭沉思著

LONG
);

  set("exits", ([
"out" : "/open/world1/wilfred/sand/room45",
]));

  set("item_desc", ([
"一臉賊樣的人" : "一個身穿黑色襯衫，深藍色牛仔褲的人，正對著藍圖發呆。\n他的武功\己經到了一擊被殺的境界。\n",
"藍圖" : "上面密密麻麻的都是線條，似乎是此城的地圖，右邊的空白處寫了數千行的程式碼。\n" ,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

