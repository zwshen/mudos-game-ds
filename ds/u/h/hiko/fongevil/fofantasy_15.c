inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
你已經進入了遺跡幻之試驗，感覺到空氣中有很多不穩的
氣息，看來似乎到了一個不簡單的陣法了，不小心一點的話可
能很難突破這裡，這裡看來應該是四幻陣的天之陣，感覺有些
無法理解的東西。
LONG
    );
 set("exits",([
"west" : __DIR__"fofantasy_16",
"east" : __DIR__"fofantasy_19",
"north" : __DIR__"fofantasy_17",
"south" : __DIR__"fofantasy_18",
]));
setroom();
setup();
}             















