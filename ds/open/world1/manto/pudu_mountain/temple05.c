inherit ROOM;

void create()
{
        set("short", "松林");
        set("long", @LONG
這片松林南有普渡寺，北倚參天之岩峰，兩邊俱是萬丈深淵。松林所
在凌空而出。其實普渡寺本身所在及是一塊半凌空地飛岩。冷冽的寒風盡
數被北端的天岩所拒，此處松林竟是風平氣和。微風拂動，青松搖晃，卻
也聽不到松濤之聲。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple08",
  "south" : __DIR__"temple04",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
