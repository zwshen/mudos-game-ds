inherit ROOM;

void create()
{

set("short","東側廂房");
set("long", @LONG
這是一間高級的房間, 這裡的擺設都是高級裝潢, 不是普通人能住的
起, 這裡的氣氛很好很適合來做某些事.
LONG
);
set("light",1);
set("exits", ([                
         
        "west" : __DIR__"up_1.c",   
         
               ]));

 setup();
}

