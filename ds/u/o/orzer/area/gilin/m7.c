inherit ROOM;
void create()
{
        set("short","山坡下");
        set("long",@LONG
你穿過了山坡來到了山坡下，前方是一座廣闊的森林，樹叢枝葉茂
密，可是卻隱隱傳來一股寒氣，令你感到不寒而慄，森林中有著奇特的
危機，讓人感覺有些害怕，不知道潛伏著什麼危險。
LONG
        );
        set("exits", ([
  "north" : __DIR__"t1",
  "southeast" : __DIR__"m6",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




