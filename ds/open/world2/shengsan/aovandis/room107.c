// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"餐\廳服務台"NOR);
	set("long", @LONG
浪漫的氣氛充斥其中，好讓人醉心。溫馨的氣氛使你有種流連忘返的
情緒。牆上掛了一幅壁畫(picture)，蠻大張的。服務台上有本黑色的價
目表(note)。如果需要可以請服務人員為你服務。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room108",
	    "south": __DIR__"room109",
	    "west" : __DIR__"room080",
            ]));
 set("item_desc",([
        "picture":@PICTURE

   ★
   ∵ .           ∵∵          .  ∵. ★       ∵     .  
  ┌──┐  .    ∵★   .  ☆            ..         ☆    
  │▍▍│  ☆             ┌───┐ ...
  │    │     ∵    ★    │ ▊ ▊│          ∵   ★
  │▍▍│                 │      │
  │    │             ┌─┤ ▊ ▊│     ┼      ☆      
  │▍▍│        ∵   │▃│      │     │    ★        
  │    ├───┐     │  │ ▊ ▊│    ／＼            
  │▍▍│      │     │▃│      │   │  │
  │    │▉ ▉ │     │  │ ▊ ▊│ ┌┘  └┐
  │▍▍│      │     │▃│      │ │■  ■│          
  │    │▉ ▉ │     │  │ ▊ ▊├─       └─┐       
  │▍▍│      │     │  │      │ ■╭─╮ ■ │
  │    │▉ ▉────── ─┐ ▊│   │  │    │     
  │▍▍│    │ �� �� �� ��  │   │ ■│  │ ■ │     
  │    │    │              │ ▊│   │  │    │          
  │    │    │ �� �� �� ��  │   │   │  │    │      

PICTURE
,
        "note":@NOTE

┌───────────────────────────┐
│ 價 錢                種類  餐點                      │
└───────────────────────────┘
      30 .............. 食物  沙拉(Salad)               
     700 .............. 食物  牛排(Beefsteak)           

    
NOTE
,
         ]));
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}

