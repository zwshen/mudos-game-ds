#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
 set("short","鐵舖");
 set("long",@LONG
一間黑黑髒髒的鐵舖，一旁的牆邊排著未成形的刀胚及炭堆，角
落的桌子旁坐著一個壯碩的鐵匠，正在畫著奇怪的圖形，桌子上還放
著一本冊子跟一本名刀鑑，用來煉鐵的火爐並沒有升火。
LONG
    );
   set("exits",([ 
       "east":__DIR__"room13",
   ]));

   set("no_clean_up",0);
   set("light",1);
   set("item_desc", ([
       "冊子" : "一本只有書皮的冊子，上面寫著"HIY"【奇甲之鑄成】"NOR"－備前．剛  著。\n",
       "名刀鑑" : "寫著名刀的介紹跟圖案，你仔細翻看，裡面記載了以下名刀：\n\n"
                 +"\t    "MAG"妖刀"HIR"．"HIC"村雨"NOR"(Murasame katana)\n"
                 +"\t    "HIW"名刀"HIR"．"HIC"虎徹"NOR"(Kote katana)\n"
                 +"\t    "HIW"傳天國作"HIR"．"HIC"小烏丸太刀"NOR"(Shouugan katana)\n"
                 +"\t    "MAG"惡鬼刀"HIR"．"NOR""GRN"骨葬"NOR"(Hide-bone katana)\n"
                 +"\t    "HIW"備前長船"NOR"(Bizen-chousen katana)\n"
                 +"\t    "HIY"菊"HIW"一文字"NOR"(Kiku-ichimonji katana)\n"
                 +"\t    "HIM"櫻亂舞"NOR"(Sakura-ranbu katana)\n\n",
      ]));
   set("objects",([
      __DIR__"npc/bizen-gou":1,
      ]));
   setup();
}            
