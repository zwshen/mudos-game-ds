inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你來到了同樣的房間，房間的另一個出口也是充滿著水，
你已經知道如何通過了，只要把機關解除掉便可以過了，但是
眼前卻找不到有任何機關，看來是在之前就出現過了，如果還
是走不過去就回去繞繞吧。
LONG);
set("exits",([
"south":__DIR__"fowater_14", 
"northeast":__DIR__"fowater_12",
"northwest":__DIR__"fowater_10",
]));
set("high_water","south");
setroom();
setup();
}             









