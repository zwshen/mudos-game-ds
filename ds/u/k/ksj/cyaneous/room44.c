inherit ROOM;

void create()
{
        set("short", "商店街－跳蚤市場");
        set("long", @LONG
這裡是一處熱鬧的舊貨市場，地上擺滿了許多二手貨品，如果有需要也可以
    變賣你身上的物品。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room43",
  "northeast" : __DIR__"room41",
  //"north" : __DIR__"room34",
  //"east" : __DIR__"room43",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}

