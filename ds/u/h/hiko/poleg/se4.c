inherit ROOM;
void create()
{
        set("short", "泊浪村海灘");        
        set("long",@LONG
這裡是柏浪村港口附近海灘，這裡離港口已經有一段距離了，因
此也比較少人了，不過感覺起來卻不會十分寂寞，四處都有十分多的
生物在這裡活動著例如寄居蟹以及海鳥們，而且有著一望無際的碧藍
海天，讓人有著和自然一體的感覺。
LONG
        );
        set("exits", ([
   "north" : __DIR__"se7",
   "southeast" : __DIR__"se5",
   "west" : __DIR__"se3", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}










