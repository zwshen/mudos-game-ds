inherit ROOM;

void create()
{

set("short","小石路");
set("long", @LONG
這裡是神木村荒郊外的小路, 地上都是泥土和小石頭, 讓你走起來非
常不順暢, 順著這條道路走下去可到達神木村的海灘.
LONG
);
set("outdoors", "land");

set("exits", ([                
         "west" : __DIR__"rr_5.c", 
         "southwest" : __DIR__"rr_7.c", 
    
   ]));

 setup();
}

