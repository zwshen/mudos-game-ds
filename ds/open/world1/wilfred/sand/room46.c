inherit ROOM;

void armageddon();

void create()
{
  set ("short", "磐龍險峻");
  set ("long", @LONG
此處山形勢險，有如伏龍盤踞，是為易守難攻之地形，山岩粼粼
，樹木稀稀落落，加上有如護城河般大江阻隔，使得這裡宛如天然城
堡，固若金湯，難以進入。
LONG
);

  set("exits", ([
  "south" : __DIR__"room47",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void reset()
{
	if( !query("armageddon")
// ||
//    random(4)) {
	) { // random(4) 沒作用吧-alick
        ::reset();
            return;
    }
        ::reset();
  tell_room(this_object(),"磐龍山又回復了生機 ....\n");

  set ("short", "磐龍險峻");
  set ("long", @LONG
此處山形勢險，有如伏龍盤踞，是為易守難攻之地形，山岩粼粼
，樹木稀稀落落，加上有如護城河般大江阻隔，使得這裡宛如天然城
堡，固若金湯，難以進入。
LONG
);

  set("exits", ([
  "south" : __DIR__"room47",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("no_recall",1);
  delete("armageddon");
  setup();
}

void armageddon()
{
  set ("short", "廢墟");
  set ("long", @LONG

只見遍地荒蕪，殘垣敗瓦，枯焦的樹木似乎在訴說著
大地的無奈，跳動的火光，有如上百隻邪惡的眼晴。

磐龍山一片死寂。

LONG
);
  delete("exits");
  delete("no_recall");
  set("armageddon",1);
}

int room_effect(object me)
{
  if(!query("armageddon")) return 1;
  switch(random(5))
  {
    case 1 : tell_room(this_object(),"一陣冷風吹來，教人直打哆嗦。\n");
             break;
    case 2 : tell_room(this_object(),"四周一片死寂。\n");
             break;
    case 3 : tell_room(this_object(),"天空的雲是鐵灰色的，風帶動著鐵色雲氣，有如滾滾江水。\n");
             break;
    default : return 1;
    }
  return 1;
}

