inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
經過不斷的測驗後，你已經走到了測驗的一半位置了，想
到終於快要接近終點後，你便就又鼓起勇氣全速前進了，但是
眼前的難關還是一樣險阻，看來到了現在還是一樣不能大意，
不然可能會前功盡棄。
LONG);
set("exits",([
"north":__DIR__"fowater_13", 
"southeast":__DIR__"fowater_17",
"southwest":__DIR__"fowater_15",
]));
setroom();
setup();
}             









