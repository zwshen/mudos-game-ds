inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你在不斷受到各種考驗的途中，慢慢的感到體力有些不支
，但是卻還是努力撐著身體前進，現在似乎離終點還有許多路
程，眼前所見皆是被水所反射的海藍色，雖然景色不錯，卻是
身處艱險中。
LONG);
set("exits",([
"south": __DIR__"fowater_10", 
"east": __DIR__"fowater_8",
]));
setroom();
setup();
}             









