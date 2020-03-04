inherit ROOM;

void create()
{
        set("short", "大帳");
        set("long", @LONG
雖然是行軍營帳，但是十分舒適講究，地上鋪著厚厚的錦氈
，帳篷四周的縫隙都用毛皮緊緊地包裹起來，秋天的寒風一絲也
不會吹進來。帳篷的一角放著一張大床，足可以讓兩個人安睡，
帳篷的另一邊放著一張松木方桌，兩邊擺著兩把椅子，桌子上擺
著一套紫砂茶具，而在帳篷中心放著一個精巧實用的銅火爐，現
在上面放著一壺開水，使得整個帳篷都是暖洋洋的。  
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"camp020",
]));
 set("objects", ([
       __DIR__"mob/general" : 1,
                ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

