inherit __DIR__"fireroom";
void create()
{
 set("short","遺跡─火");
 set("long",@LONG
你已經進入了遺跡火之試驗，這裡到處冒出火焰令你感到
十分不舒服，你在考驗的路途中不斷前進，但是好像無止盡一
般，讓你有些怯意了，再加上不斷的火炎摧殘著，你可能快要
無法承受了。
LONG
);
 set("exits",([
"east":__DIR__"fofire_9",
"west":__DIR__"fofire_6",
"south":__DIR__"fofire_7",
"north":__DIR__"fofire_15",
]));
 set("no_clean_up",0);
 set("light",1);
 set("no_map",1);
 set("no_recall","這裡陰氣太重上天聽不到你呼喚的\n");
 setup();
}             







