#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"騰空書院二樓"NOR);

 set("long",@LONG
你向上爬, 再一次驚異於這個書院架在空中的鬼斧神工, 你發現你的四周是一些
木樁, 其中有一個上面貼了一張泛黃的羊皮紙 (paper), 你同時也發現這裡的風景極
好, 甚至可以看到鶴子橋,朝天湖等名勝景觀 , 不管怎麼樣, 還是先看看紙上寫了什
麼吧! 
LONG
    );
 set("exits",([ "north":__DIR__"wood1.c",
    ]));
 set("item_desc",([
	"paper":"這張紙上寫著:在這個世界中, 有些地方充斥著迷宮, 迷宮一般來說
都有一定的走法, 如: 往北走幾步, 往西走幾步等....萬一真的走不出
去, 也可以用recall回到朝天樓或夢幻旅館等....我們為了使你可以更
熟悉如何抓到規律, 應此在這裡往北就有一個迷宮, 希望你早日熟悉如
何抓到規律!\n",
    ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
