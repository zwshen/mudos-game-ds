inherit __DIR__"fantasyroom";
void create()
{
 set("short","遺跡─幻");
set("long",@LONG
這裡是天之陣的二門，有著許多無法辨認的幻影，在如此
詭異的氣氛促使下，你也開始疑神疑鬼起來了，不過只要心神
沒法穩穩的安定下來，那麼也就不可能輕易通過測驗了，也許
這裡的最大難關就是心魔。
LONG
    );
 set("exits",([
"northeast" : __DIR__"fofantasy_20",
"northwest" : __DIR__"fofantasy_12",
"south" : __DIR__"fofantasy_15",
]));
set("no_random_move","northeast");
setroom();
setup();
}             
















